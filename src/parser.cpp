#include "parser.hpp"
#include "ast.hpp"

void Parser::Parse(std::vector<Tokenizer> VectorOfTokens)
{
	for (std::size_t i = 0; i < VectorOfTokens.size(); i++)
	{
		if (VectorOfTokens[i].GetToken() == Tokens::Integer)
		{
			if (VectorOfTokens[i + 1].GetValue() == "main")
			{
				if (VectorOfTokens[i + 2].GetToken() == Tokens::OpenParen &&
					VectorOfTokens[i + 3].GetToken() == Tokens::CloseParen)
				{
					if (VectorOfTokens[i + 5].GetToken() == Tokens::Return)
					{
						if (VectorOfTokens[i + 6].GetToken() == Tokens::IntLit)
						{
							Program = CreateProgram({
								CreateFunction("main", {
									CreateReturn(CreateConstant(0))
									}
								)}
							);
						}
					}
				}
			}
		}
	}

	Program.PrintAST(Program);
}
