#include "tokenizer.hpp"
#include "parser.hpp"

int main(int argc, const char* argv[])
{
	tokenizer tokenizer{};
	tokenizer.tokenize(argv);
	tokenizer.displaytokens();
	parser parser{};
	parser.parse(tokenizer.getvtokens());
	
	return 0;
}
