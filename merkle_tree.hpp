#ifndef MERKLE_TREE_H_
#define MERKLE_TREE_H_

#include <vector>
#include <string>
#include <memory>
#include "merkle_node.hpp"


class merkle_tree
{
private:
	std::shared_ptr<merkle_node> root;

	std::shared_ptr<merkle_node> build(std::vector<std::string> values);

public:
	explicit merkle_tree(std::vector<std::string> values);
	virtual ~merkle_tree();
	std::string get_hash_top() const;
	const merkle_node * get_root() const;

};

#endif // MERKLE_TREE_H_
