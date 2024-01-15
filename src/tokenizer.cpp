﻿#include "tokenizer.hpp"

std::vector<Tokenizer>& Tokenizer::Tokenize(const char* ArgV[])
{
	std::ifstream File{ ArgV[1] };

	if (IsFileValid(File, ArgV[1]))
	{
		// Read character by character from File and push_back each character to char vector FiveInVChar
		while (File >> std::noskipws >> CurrentChar) { FileInVChar.push_back(CurrentChar); }
		File.close();

		// Turn vector of chars, for example {'e', 'x', ' ', '3', '2', ';', 'a'} into vector of strings.
		// For example {"ex", " ", "32", ";", "a"} by detecting characters such as semicolons.
		// When a character such as this is detected, push back anything before the semicolon (for example) to FileInVString. 
		for (const auto& CVC : FileInVChar)
		{
			if (CVC != ' ' && CVC != ';' && CVC != '\n')
			{
				Buffer.push_back(CVC);
			}
			else if (CVC == ';')
			{
				FileInVString.push_back(Buffer);
				FileInVString.push_back(";");
				Buffer = "";
			}
			else 
			{
				FileInVString.push_back(Buffer);
				Buffer = "";
			}
		}

		// Push_back Buffer to FileInVString if its not empty
		if (Buffer != "") FileInVString.push_back(Buffer);

		// Erase all empty strings in the vector
		for (std::size_t i = 0; i < FileInVString.size(); ++i)
		{
			if (FileInVString[i] == "") FileInVString.erase(FileInVString.begin() + i);
		}

		// Make VTokens the same size as FileInVString
		VTokens.resize(FileInVString.size());

		// Assign Token and Value of current Token 
		for (std::size_t i = 0; i < FileInVString.size(); ++i)
		{
			if (FileInVString[i] == "return")
			{
				VTokens[i].Token = Tokens::Return;
				VTokens[i].Value = FileInVString[i];
			}
			else if (IsIntLit(FileInVString[i]))
			{
				VTokens[i].Token = Tokens::IntLit;
				VTokens[i].Value = FileInVString[i];
			}
			else if (IsIdentifier(FileInVString[i]))
			{
				VTokens[i].Token = Tokens::Identifier;
				VTokens[i].Value = FileInVString[i];
			}
			else if (FileInVString[i] == ";")
			{
				VTokens[i].Token = Tokens::SemiColon;
				VTokens[i].Value = FileInVString[i];
			}
			else
			{
				VTokens[i].Token = Tokens::NoToken;
				VTokens[i].Value = FileInVString[i];
			}
		}
	}

	return VTokens;
}

void Tokenizer::DisplayTokens() const
{
	// Display all tokens created
	for (const auto& CVT : VTokens)
	{
		if (CVT.Token == Tokens::Return)
		{
			std::cout << "[ " << CVT.Value << " ]" << " = Return" << "\n";
		}
		else if (CVT.Token == Tokens::IntLit)
		{
			std::cout << "[ " << CVT.Value << " ]" << " = IntLit" << "\n";
		}
		else if (CVT.Token == Tokens::Identifier)
		{
			std::cout << "[ " << CVT.Value << " ]" << " = Identifier" << "\n";
		}
		else if (CVT.Token == Tokens::SemiColon)
		{
			std::cout << "[ " << CVT.Value << " ]" << " = SemiColon" << "\n";
		}
		else
		{
			std::cout << "[ " << CVT.Value << " ]" << " = NoToken" << "\n";
		}
	}
}

bool Tokenizer::IsIntLit(const std::string String) const
{
	// Check if any character of the string is not numerical
	for (const auto& CC : String)
	{
		if (std::isalpha(CC) || CC == ';') return false;
	}

	return true;
}

bool Tokenizer::IsIdentifier(const std::string String) const
{
	// Check if first character of String is alphabetical and if String is a keyword
	if (isalpha(String[0]) && !IsKeyword(String)) return true;
	else return false;
}

bool Tokenizer::IsFileValid(const std::ifstream& File, const char* ArgV1) const
{
	// Check if file ends in .eoss
	if (ArgV1[strlen(ArgV1) - 1] != 's' || ArgV1[strlen(ArgV1) - 2] != 's' ||
		ArgV1[strlen(ArgV1) - 3] != 'o' || ArgV1[strlen(ArgV1) - 4] != 'e' ||
		ArgV1[strlen(ArgV1) - 5] != '.')
	{
		std::cerr << "\033[1;31meoss-lang > FILE PROVIDED LACKS .eoss EXTENSION\033[0m\n\n";
		assert(false);
		return false;
	}

	// Check if file exists
	if (!File)
	{
		std::cerr << "\033[1;31meoss-lang > FILE PROVIDED DOES NOT EXIST\033[0m\n\n";
		assert(false);
		return false;
	}

	return true;
}

bool Tokenizer::IsKeyword(const std::string String) const
{
	// Compare String to every keyword in eoss-lang
	if (String == "return") return true;

	else return false;
}

const std::vector<char>& Tokenizer::GetFileInVChar() const { return FileInVChar; }
const std::vector<std::string>& Tokenizer::GetFileInVString() const { return FileInVString; }
const std::vector<Tokenizer>& Tokenizer::GetVTokens() const { return VTokens; }
const std::string& Tokenizer::GetBuffer() const { return Buffer; }
const std::string& Tokenizer::GetValue() const { return Value; }
char Tokenizer::GetCurrentChar() const { return CurrentChar; }
const Tokens& Tokenizer::GetToken() const { return Token; }

