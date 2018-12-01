#include <iostream>
#include "block.hpp"
#include "blockchain.hpp"


int main(int argc, char *argv[])
{
	blockchain blc;

	for (unsigned i = 0; i < 10; ++i)
	{
		std::cout << "Mining block " << i << "\n";
		block bl(i, "data");
		blc.add_block(bl);
	}

	return 0;
}
