#include <iostream>
#include <utility>
#include "ast.hpp"
#include "parser.hpp"

// goofy ahh function 💀💀💀💀💀💀💀💀🤣🤣💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀🤣
void AST::PrintAST(AST Program) const
{
	for (std::size_t i = 0; i < Program.Children.size(); i++)
	{
		std::cout << Program.Children[i].Name << "\n";
		std::cout << Program.Children[i].Value << "\n";
		Program.Children[i].PrintVariant();
		for (std::size_t j = 0; j < Program.Children[i].Children.size(); j++)
		{
			std::cout << Program.Children[i].Children[j].Name << "\n";
			std::cout << Program.Children[i].Children[j].Value << "\n";
			Program.Children[i].Children[j].PrintVariant();
			for (std::size_t x = 0; x < Program.Children[i].Children[j].Children.size(); x++)
			{
				std::cout << Program.Children[i].Children[j].Children[x].Name << "\n";
				std::cout << Program.Children[i].Children[j].Children[x].Value << "\n";
				Program.Children[i].Children[j].Children[x].PrintVariant();
			}
		}
	}
}

void AST::PrintVariant() const
{
	if (this->Variant == Variant::Function)
	{
		std::cout << "Variant : function\n";
	}
	else if (this->Variant == Variant::Constant)
	{
		std::cout << "Variant : constant\n";
	}
	else if (this->Variant == Variant::Return)
	{
		std::cout << "Variant : return\n";
	}
	else if (this->Variant == Variant::Program)
	{
		std::cout << "Variant : Program\n";
	}
}

AST CreateProgram(std::vector<AST> Children)
{
	AST Program;
	Program.Variant = Variant::Program;

	for (std::size_t i = 0; i < Children.size(); i++)
	{
		Program.Children.push_back(Children[i]);
	}

	return Program;
}

AST CreateFunction(std::string Name, std::vector<AST> Children)
{
	AST Function;
	Function.Variant = Variant::Function;

	Function.Name = Name;

	for (std::size_t i = 0; i < Children.size(); i++)
	{
		Function.Children.push_back(Children[i]);
	}

	return Function;
}

AST CreateReturn(AST Statement)
{
	AST Return;
	Return.Variant = Variant::Return;

	Return.Children.push_back(Statement);

	return Return;
}

AST CreateConstant(const int Num)
{
	AST Constant;
	Constant.Variant = Variant::Constant;

	Constant.Value = Num;

	return Constant;
}
