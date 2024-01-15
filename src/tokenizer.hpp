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
	SemiColon
};

class Tokenizer
{
private:
	std::vector<char> FileInVChar{};
	std::vector<std::string> FileInVString{};
	std::vector<Tokenizer> VTokens{};

	std::string Buffer{};
	std::string Value{};

	char CurrentChar{};
	Tokens Token{};
public:
	std::vector<Tokenizer>& Tokenize(const char* ArgV[]);
	void DisplayTokens() const;

	bool IsIntLit(const std::string String) const;
	bool IsIdentifier(const std::string String) const;
	bool IsFileValid(const std::ifstream& File, const char* ArgV1) const;
	bool IsKeyword(const std::string String) const;

	const std::vector<char>& GetFileInVChar() const;
	const std::vector<std::string>& GetFileInVString() const;
	const std::vector<Tokenizer>& GetVTokens() const;
	const std::string& GetBuffer() const;
	const std::string& GetValue() const;
	char GetCurrentChar() const;
	const Tokens& GetToken() const;
};

#endif // !TOKENIZER_HPP

