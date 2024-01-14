#include "tokenizer.hpp"

int main(int ArgC, char* ArgV[])
{
	Tokenizer Tokenizer{};
	Tokenizer.Tokenize(const_cast<const char**>(ArgV));
	Tokenizer.DisplayTokens();
	
	return 0;
}
