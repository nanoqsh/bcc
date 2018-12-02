#include <iostream>
#include "block.hpp"
#include "blockchain.hpp"
#include "transaction.hpp"
#include <vector>
#include <string>
#include "merkle_tree.hpp"
#include "merkle_node.hpp"


int main(int argc, char *argv[])
{
	std::vector<transaction> transactions = {
		transaction("1", "2", "Hello!"),
		transaction("2", "1", "Hi sup!"),
		};
	
	block bl(1, transactions);
	blockchain blchain;
	blchain.add_block(bl);

	std::cout << bl.get_hash() << "\n";

	std::getchar();
	return 0;
}
