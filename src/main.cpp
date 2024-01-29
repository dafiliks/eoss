#include "tokenizer.hpp"

int main(int argc, char* argv[])
{
	tokenizer tokenizer{};
	tokenizer.tokenize(const_cast<const char**>(argv));
	tokenizer.displaytokens();
	
	return 0;
}
