#ifndef MERKLE_TREE_H_
#define MERKLE_TREE_H_

#include <vector>
#include <string>
#include "merkle_node.h"


class merkle_tree
{
private:
	merkle_node * root;

	merkle_node * build(std::vector<std::string> values);

public:
	explicit merkle_tree(std::vector<std::string> values);
	virtual ~merkle_tree();
	std::string get_hash_top() const;
	const merkle_node * get_root() const;

};

#endif // MERKLE_TREE_H_
