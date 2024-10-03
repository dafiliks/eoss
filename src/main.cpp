#include "tokenizer.hpp"
#include "parser.hpp"

int main(int argc, const char* argv[])
{
	Tokenizer Tokenizer{};
	Tokenizer.Tokenize(argv);
	Tokenizer.DisplayTokens();
	Parser Parser{};
	Parser.Parse(Tokenizer.GetVectorOfTokens());
	
	return 0;
}
