#include "tokenizer.hpp"

std::vector<Tokenizer> Tokenizer::Tokenize(const char* argv[])
{
	std::ifstream File{ argv[1] };

	if (IsFileValid(File, argv[1]))
	{
		while (File >> std::noskipws >> CurrentChar) 
		{
			FileInVectorOfChars.push_back(CurrentChar); 
		}
		File.close();

		for (std::size_t i = 0; i < FileInVectorOfChars.size(); ++i)
		{
			if (FileInVectorOfChars[i] != ' ' && FileInVectorOfChars[i] != ';'
			&& FileInVectorOfChars[i] != '\n' && FileInVectorOfChars[i] != '(')
			{
				Buffer.push_back(FileInVectorOfChars[i]);
			}
			else if (FileInVectorOfChars[i] == ';' || FileInVectorOfChars[i] == '(')
			{
				FileInVectorOfStrings.push_back(Buffer);
				std::string S(1, FileInVectorOfChars[i]);
				FileInVectorOfStrings.push_back(S);
				Buffer = "";
			}
			else 
			{
				if (Buffer != "")
				{
					FileInVectorOfStrings.push_back(Buffer);
					Buffer = "";
				}
			}
		}

		if (Buffer != "")
		{
			FileInVectorOfStrings.push_back(Buffer);
		}

		for (std::size_t i = 0; i < FileInVectorOfStrings.size(); ++i)
		{
			if (FileInVectorOfStrings[i] == "")
			{
				FileInVectorOfStrings.erase(FileInVectorOfStrings.begin() + i);
			}
		}

		VectorOfTokens.resize(FileInVectorOfStrings.size());

		for (std::size_t i = 0; i < FileInVectorOfStrings.size(); ++i)
		{
			if (FileInVectorOfStrings[i] == "return")
			{
				VectorOfTokens[i].Token = Tokens::Return;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (FileInVectorOfStrings[i] == "int")
			{
				VectorOfTokens[i].Token = Tokens::Integer;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (FileInVectorOfStrings[i] == "{")
			{
				VectorOfTokens[i].Token = Tokens::OpenBrace;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (FileInVectorOfStrings[i] == "}")
			{
				VectorOfTokens[i].Token = Tokens::CloseBrace;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (FileInVectorOfStrings[i] == "(")
			{
				VectorOfTokens[i].Token = Tokens::OpenParen;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (FileInVectorOfStrings[i] == ")")
			{
				VectorOfTokens[i].Token = Tokens::CloseParen;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (IsIntLit(FileInVectorOfStrings[i]))
			{
				VectorOfTokens[i].Token = Tokens::IntLit;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (IsIdentifier(FileInVectorOfStrings[i]))
			{
				VectorOfTokens[i].Token = Tokens::Identifier;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else if (FileInVectorOfStrings[i] == ";")
			{
				VectorOfTokens[i].Token = Tokens::SemiColon;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
			else
			{
				VectorOfTokens[i].Token = Tokens::NoToken;
				VectorOfTokens[i].Value = FileInVectorOfStrings[i];
			}
		}
	}

	return VectorOfTokens;
}

void Tokenizer::DisplayTokens() const
{
	for (std::size_t i = 0; i < VectorOfTokens.size(); ++i)
	{
		if (VectorOfTokens[i].Token == Tokens::Return)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = Return" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::Integer)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = Integer" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::OpenBrace)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = OpenBrace" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::CloseBrace)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = CloseBrace" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::OpenParen)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = OpenParen" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::CloseParen)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = CloseParen" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::IntLit)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = IntegerLit" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::Identifier)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = Identifier" << "\n";
		}
		else if (VectorOfTokens[i].Token == Tokens::SemiColon)
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = SemiColon" << "\n";
		}
		else
		{
			std::cout << "[ " << VectorOfTokens[i].Value << " ]" << " = NoToken" << "\n";
		}
	}
}

bool Tokenizer::IsIntLit(const std::string String) const
{
	for (std::size_t i = 0; i < String.size(); ++i)
	{
		if (std::isalpha(String[i]) || String[i] == ';')
		{
			return false;
		}
	}

	return true;
}

bool Tokenizer::IsIdentifier(const std::string String) const
{
	if (isalpha(String[0]) && !IsKeyword(String))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tokenizer::IsFileValid(const std::ifstream& File, const char* argv1) const
{
	if (argv1[strlen(argv1) - 1] != 's' || argv1[strlen(argv1) - 2] != 's' ||
		argv1[strlen(argv1) - 3] != 'o' || argv1[strlen(argv1) - 4] != 'e' ||
		argv1[strlen(argv1) - 5] != '.')
	{
		std::cerr << "\033[1;31meoss-lang > File PROVIDED LACKS .eoss EXTENSION\033[0m\n\n";
		assert(false);
		return false;
	}

	if (!File)
	{
		std::cerr << "\033[1;31meoss-lang > File PROVIDED DOES NOT EXIST\033[0m\n\n";
		assert(false);
		return false;
	}

	return true;
}

bool Tokenizer::IsKeyword(const std::string String) const
{
	if (String == "return")
	{
		return true;
	}

	else return false;
}

const std::vector<char> Tokenizer::GetFileInVectorOfChars() const { return FileInVectorOfChars; }
const std::vector<std::string> Tokenizer::GetFileInVectorOfStrings() const { return FileInVectorOfStrings; }
const std::vector<Tokenizer> Tokenizer::GetVectorOfTokens() const { return VectorOfTokens; }
const std::string Tokenizer::GetBuffer() const { return Buffer; }
const std::string Tokenizer::GetValue() const { return Value; }
char Tokenizer::GetCurrentChar() const { return CurrentChar; }
const Tokens Tokenizer::GetToken() const { return Token; }

