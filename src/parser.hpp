#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <fstream>  
#include "tokenizer.hpp"
#include "ast.hpp"

class Parser : public Tokenizer
{
private:
	AST Program{};
public:
	void Parse(std::vector<Tokenizer> VectorOfTokens);
};

#endif
