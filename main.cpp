#include <iostream>
#include "block.hpp"
#include "blockchain.hpp"

#include <vector>
#include <string>
#include "merkle_tree.h"
#include "merkle_node.h"
#include "sha256/sha256.hpp"


int main(int argc, char *argv[])
{
	std::vector<std::string> values = { "foo", "bar", "baz" };
	merkle_tree tree(values);

	std::cout << tree.get_hash_top() << "\n";

	const merkle_node * root = tree.get_root();
	std::cout << root->get_hash() << "\n";

	const merkle_node * left = root->get_left();
	const merkle_node * right = root->get_right();
	std::cout << sha256(left->get_hash() + right->get_hash()) << "\n";

	return 0;
}
