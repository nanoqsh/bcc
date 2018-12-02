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
		transaction(2, 1, "Hi sup!"),
		};
	
	block bl(1, transactions);
	blockchain blchain;
	blchain.add_block(bl);

	std::cout << bl.get_hash() << "\n";

	std::getchar();
	return 0;
}
