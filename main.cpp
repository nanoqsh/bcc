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

	/*
	 * Create a blockchain
	 * Set the difficulty == 3
	 * It means mined block hashes will start with three zeros ("000")
	 */
	blockchain blchain(3);

	/*
	 * Blockchain blocks.
	 * Each of block contains transactions
	 * Each of transaction contains:
	 *		- sender ID
	 *		- recipient ID
	 *		- message text
	 */
	std::vector<block> blocks = {
		block(1, {
			transaction(1, 2, "Hello!"),
			transaction(2, 1, "Knuckle down"),
			transaction(2, 1, "Read 'em and weep")
			}),
		block(2, {
			transaction(2, 3, "Wild goose chase"),
			transaction(3, 2, "Curiosity killed the cat")
			}),
		block(3, {
			transaction(1, 3, "On the same page"),
			transaction(1, 2, "My cup of coffee")
			})
		};
	
	/*
	 * Mine each of block
	 */
	for (block & b : blocks)
	{
		std::cout << "Mine...\n";
		blchain.add_block(b);
		std::cout << "Mined!\n";

		/*
		 * Show block's data
		 * The merkle root consists of all transaction's hashes
		 */
		std::cout << "\nBlock #" << b.get_index() << " data: \n";
		std::cout << b.to_debug_string() << "\n";

		/*
		 * Show block's history
		 */
		std::cout << "\nBlock history: \n";
		for (const transaction & tr : b.get_transactions())
			std::cout << "\t" << tr.to_string() << "\n";

		std::cout << "\n";
	}

	return 0;
}
