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
	std::vector<Tokenizer> Tokenize(int ArgC, char* ArgV[]);
	void DisplayTokens() const;

	// Boolean functions
	bool IsIntLit(std::string String) const;
	bool IsIdentifier(std::string String) const;
	bool IsFileValid(std::ifstream& File, char* ArgV1) const;
	bool IsKeyword(std::string String) const;

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

