#ifndef AST_HPP
#define AST_HPP

#include <string>

class Function;
class Program;
class Statement;
class Return;
class Expression;

class Expression
{
public:
	int constant{};
};

class Return
{
public:
	Expression exp{};
};

class Statement
{
public:
	Return ret{};
};

class Function
{
public:
	std::string name{};
	Statement body{};
};

class Program
{
public:
	Function func_def{};
};

class AST
{
public:
	Program AST;

	void printAST();
};

#endif
