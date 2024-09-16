#include "parser.hpp"
#include "ast.hpp"

void parser::parse(std::vector<tokenizer> vtokensP)
{
	AST AST;
	for (std::size_t i = 0; i < vtokensP.size(); i++)
	{
		if (vtokensP[i].gettoken() == tokens::_int)
		{
			if (vtokensP[i + 1].getvalue() == "main")
			{
				if (vtokensP[i + 2].gettoken() == tokens::_open_paren &&
					vtokensP[i + 3].gettoken() == tokens::_close_paren)
				{
					AST.AST.func_def.name = "main";
					if (vtokensP[i + 5].gettoken() == tokens::_return)
					{
						if (vtokensP[i + 6].gettoken() == tokens::_intlit)
						{
							AST.AST.func_def.body.ret.exp.constant = std::stoi(vtokensP[i + 6].getvalue());
						}
					}
				}
			}
		}
	}
	AST.printAST();
}
