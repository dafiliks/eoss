#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>

enum class tokens
{
	_notoken,
	_return,
	_intlit,
	_identifier,
	_semicolon
};

class tokenizer
{
private:
	std::vector<char> filevchar{};
	std::vector<std::string> filevstring{};

	// filevchar -> filevstring -> vtokens.value
	std::vector<tokenizer> vtokens{};

	std::string buffer{};
	char cchar{};

	std::string value{};
	tokens token{};
public:
	std::vector<tokenizer> tokenize(const char* argv[]);
	void displaytokens() const;

	bool isintlit(const std::string string) const;
	bool isidentifier(const std::string string) const;
	bool isfilevalid(const std::ifstream& file, const char* argv1) const;
	bool iskeyword(const std::string string) const;

	const std::vector<char> getfilevchar() const;
	const std::vector<std::string> getfilevstring() const;
	const std::vector<tokenizer> getvtokens() const;
	const std::string getbuffer() const;
	const std::string getvalue() const;
	char getcchar() const;
	const tokens gettoken() const;
};

#endif
