#include <iostream>
#include "bcc/block.hpp"
#include "bcc/blockchain.hpp"
#include "bcc/transaction.hpp"
#include <vector>
#include <string>
#include "bcc/merkle_tree.hpp"
#include "bcc/merkle_node.hpp"


int main(int argc, char *argv[])
{
	using namespace bcc;

	std::vector<transaction> transactions = {
		transaction(1, 2, "Hello!"),
		transaction(2, 1, "Sup!"),
		};
	
	block bl(1, transactions);
	blockchain blchain;

	std::cout << "Mine...\n";
	blchain.add_block(bl);
	std::cout << "Mined! Hash: " << bl.get_hash() << "\n";

	std::cout << "\nBlock data: \n";
	std::cout << bl.to_debug_string() << "\n";

	std::cout << "\nBlock history: \n";
	for (const transaction & tr : bl.get_transactions())
		std::cout << tr.to_string() << "\n";

	return 0;
}
