#include "parser.hpp"

void parser::parse(std::vector<tokenizer> vtokensP)
{
	std::ofstream pfile( "paa.json");
	for (std::size_t i = 0; i < vtokensP.size(); i++)
	{
		if (vtokensP[i].gettoken() == tokens::_intlit)
		{
			pfile << "{ type: \"num\", value: " << vtokensP[i].getvalue() << " },\n";
		}
	}
    pfile.close();
}
