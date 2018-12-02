#include "merkle_tree.h"


merkle_tree::merkle_tree(std::vector<std::string> values)
{
	this->root = this->build(values);
}

merkle_tree::~merkle_tree()
{
	delete this->root;
}

merkle_node * merkle_tree::build(std::vector<std::string> values)
{
	unsigned len = values.size();

	switch (len)
	{
	case 0:
		return new merkle_node(nullptr, nullptr);

	case 1:
		return new merkle_node(
			new merkle_node(values[0]),
			nullptr
			);

	case 2:
		return new merkle_node(
			new merkle_node(values[0]),
			new merkle_node(values[1])
			);

	default:
		unsigned half = len / 2 + len % 2;

		std::vector<std::string> left(values.begin(), values.begin() + half);
		std::vector<std::string> right(values.begin() + half, values.end());

		return new merkle_node(
			this->build(left),
			this->build(right)
			);
	}
}

std::string merkle_tree::get_hash_top() const
{
	return this->root->get_hash();
}

const merkle_node * merkle_tree::get_root() const
{
	return this->root;
}
