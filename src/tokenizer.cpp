#include "tokenizer.hpp"

std::vector<tokenizer> tokenizer::tokenize(const char* argv[])
{
	std::ifstream file{ argv[1] };

	if (isfilevalid(file, argv[1]))
	{
		while (file >> std::noskipws >> cchar) 
		{
			filevchar.push_back(cchar); 
		}
		file.close();

		for (std::size_t i = 0; i < filevchar.size(); ++i)
		{
			if (filevchar[i] != ' ' && filevchar[i] != ';' && filevchar[i] != '\n')
			{
				buffer.push_back(filevchar[i]);
			}
			else if (filevchar[i] == ';')
			{
				filevstring.push_back(buffer);
				filevstring.push_back(";");
				buffer = "";
			}
			else 
			{
				filevstring.push_back(buffer);
				buffer = "";
			}
		}

		if (buffer != "")
		{
			filevstring.push_back(buffer);
		}

		for (std::size_t i = 0; i < filevstring.size(); ++i)
		{
			if (filevstring[i] == "")
			{
				filevstring.erase(filevstring.begin() + i);
			}
		}

		vtokens.resize(filevstring.size());

		for (std::size_t i = 0; i < filevstring.size(); ++i)
		{
			if (filevstring[i] == "return")
			{
				vtokens[i].token = tokens::_return;
				vtokens[i].value = filevstring[i];
			}
			else if (isintlit(filevstring[i]))
			{
				vtokens[i].token = tokens::_intlit;
				vtokens[i].value = filevstring[i];
			}
			else if (isidentifier(filevstring[i]))
			{
				vtokens[i].token = tokens::_identifier;
				vtokens[i].value = filevstring[i];
			}
			else if (filevstring[i] == ";")
			{
				vtokens[i].token = tokens::_semicolon;
				vtokens[i].value = filevstring[i];
			}
			else
			{
				vtokens[i].token = tokens::_notoken;
				vtokens[i].value = filevstring[i];
			}
		}
	}

	return vtokens;
}

void tokenizer::displaytokens() const
{
	for (std::size_t i = 0; i < vtokens.size(); ++i)
	{
		if (vtokens[i].token == tokens::_return)
		{
			std::cout << "[ " << vtokens[i].value << " ]" << " = _return" << "\n";
		}
		else if (vtokens[i].token == tokens::_intlit)
		{
			std::cout << "[ " << vtokens[i].value << " ]" << " = _intlit" << "\n";
		}
		else if (vtokens[i].token == tokens::_identifier)
		{
			std::cout << "[ " << vtokens[i].value << " ]" << " = _identifier" << "\n";
		}
		else if (vtokens[i].token == tokens::_semicolon)
		{
			std::cout << "[ " << vtokens[i].value << " ]" << " = _semicolon" << "\n";
		}
		else
		{
			std::cout << "[ " << vtokens[i].value << " ]" << " = _notoken" << "\n";
		}
	}
}

bool tokenizer::isintlit(const std::string string) const
{
	for (std::size_t i = 0; i < string.size(); ++i)
	{
		if (std::isalpha(string[i]) || string[i] == ';')
		{
			return false;
		}
	}

	return true;
}

bool tokenizer::isidentifier(const std::string string) const
{
	if (isalpha(string[0]) && !iskeyword(string))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool tokenizer::isfilevalid(const std::ifstream& file, const char* argv1) const
{
	if (argv1[strlen(argv1) - 1] != 's' || argv1[strlen(argv1) - 2] != 's' ||
		argv1[strlen(argv1) - 3] != 'o' || argv1[strlen(argv1) - 4] != 'e' ||
		argv1[strlen(argv1) - 5] != '.')
	{
		std::cerr << "\033[1;31meoss-lang > FILE PROVIDED LACKS .eoss EXTENSION\033[0m\n\n";
		assert(false);
		return false;
	}

	if (!file)
	{
		std::cerr << "\033[1;31meoss-lang > FILE PROVIDED DOES NOT EXIST\033[0m\n\n";
		assert(false);
		return false;
	}

	return true;
}

bool tokenizer::iskeyword(const std::string string) const
{
	if (string == "return")
	{
		return true;
	}

	else return false;
}

const std::vector<char> tokenizer::getfilevchar() const { return filevchar; }
const std::vector<std::string> tokenizer::getfilevstring() const { return filevstring; }
const std::vector<tokenizer> tokenizer::getvtokens() const { return vtokens; }
const std::string tokenizer::getbuffer() const { return buffer; }
const std::string tokenizer::getvalue() const { return value; }
char tokenizer::getcchar() const { return cchar; }
const tokens tokenizer::gettoken() const { return token; }

