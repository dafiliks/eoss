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
	Return,
	IntLit,
	Identifier,
	SemiColon
};

class Tokenizer
{
private:
	// Vectors
	std::vector<char> FileInVChar{};
	std::vector<std::string> FileInVString{};
	std::vector<Tokenizer> VTokens{};

	// Strings
	std::string Buffer{};
	std::string Value{};

	// Other
	char CurrentChar{};
	Tokens Token{};
public:
	// Main functions
	std::vector<Tokenizer> Tokenize(const char* ArgV[]);
	void DisplayTokens() const;

	// Boolean functions
	bool IsIntLit(const std::string& String);
	bool IsIdentifier(const std::string& String);
	bool IsFileValid(const std::ifstream& File, const char* ArgV1);
	bool IsKeyword(const std::string& String);

	// Getters (mostly for debugging)
	std::vector<char> GetFileInVChar() const;
	std::vector<std::string> GetFileInVString() const;
	std::vector<Tokenizer> GetVTokens() const;
	std::string GetBuffer() const;
	std::string GetValue() const;
	char GetCurrentChar() const;
	Tokens GetToken() const;
};

#endif // !TOKENIZER_HPP

