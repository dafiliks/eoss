#ifndef PARSER_HPP
#define PARSER_HPP

#include "tokenizer.hpp"
#include <iostream>
#include <fstream>  

class parser : public tokenizer
{
public:
	void parse(std::vector<tokenizer> vtokensP);
};

#endif
