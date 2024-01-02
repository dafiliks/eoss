#include "tokenizer.hpp"

int main(int ArgC, char* ArgV[])
{
	Tokenizer Tokenizer{};
	Tokenizer.Tokenize(ArgC, ArgV);
	Tokenizer.DisplayTokens();
	
	return 0;
}
