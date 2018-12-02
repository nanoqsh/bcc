#include "merkle_node.hpp"


merkle_node::merkle_node(const std::string & value) :
	left(nullptr),
	right(nullptr)
{
	this->hash = sha256(value);
}

merkle_node::merkle_node(std::shared_ptr<merkle_node> left, std::shared_ptr<merkle_node> right) :
	left(left),
	right(right)
{
	std::string computed_hash;

	if (left && right)
		computed_hash = sha256(left->get_hash() + right->get_hash());
	else if (left && !right)
		computed_hash = sha256(left->get_hash() + left->get_hash());

	this->hash = computed_hash;
}

merkle_node::~merkle_node() {}

bool merkle_node::has_children() const
{
	return this->left || this->right;
}

const std::string & merkle_node::get_hash() const
{
	return this->hash;
}

const merkle_node * merkle_node::get_left() const
{
	return this->left.get();
}

const merkle_node * merkle_node::get_right() const
{
	return this->right.get();
}
