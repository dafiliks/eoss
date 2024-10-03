#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>

enum class Tokens
{
	NoToken,
	Return,
	IntLit,
	Identifier,
	SemiColon,
	Integer,
	OpenBrace,
	CloseBrace,
	OpenParen,
	CloseParen,
};

class Tokenizer
{
private:
	std::vector<char> FileInVectorOfChars{};
	std::vector<std::string> FileInVectorOfStrings{};

	std::vector<Tokenizer> VectorOfTokens{};

	std::string Buffer{};
	char CurrentChar{};

	std::string Value{};
	Tokens Token{};
public:
	std::vector<Tokenizer> Tokenize(const char* argv[]);
	void DisplayTokens() const;

	bool IsIntLit(const std::string String) const;
	bool IsIdentifier(const std::string String) const;
	bool IsFileValid(const std::ifstream& File, const char* argv1) const;
	bool IsKeyword(const std::string String) const;

	const std::vector<char> GetFileInVectorOfChars() const;
	const std::vector<std::string> GetFileInVectorOfStrings() const;
	const std::vector<Tokenizer> GetVectorOfTokens() const;
	const std::string GetBuffer() const;
	const std::string GetValue() const;
	char GetCurrentChar() const;
	const Tokens GetToken() const;
};

#endif
