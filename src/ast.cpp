#include "ast.hpp"
#include "parser.hpp"
#include <iostream>

void AST::printAST()
{
	std::cout << "Program(";
	if (AST.func_def.name != "")
	{
		std::cout << "Function(";
	}
	
}
