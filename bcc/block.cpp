#include "block.hpp"


bcc::block::block(uint32_t index, std::vector<transaction> transactions) :
	index(index),
	nonce(-1)
{
	std::vector<std::string> values;

	for (transaction & tr : transactions)
		values.push_back(tr.to_string());

	this->tree = std::make_shared<merkle_tree>(values);
	this->timestamp = std::time(nullptr);
}

bcc::block::block(const block & other) :
	index(other.index),
	nonce(other.nonce),
	tree(other.tree),
	hash(other.hash),
	timestamp(other.timestamp),
	prev_hash(other.prev_hash)
{
}

bcc::block::~block() {}

std::string bcc::block::get_hash() const
{
	return this->hash;
}

bool bcc::block::check_hash(uint32_t difficulty)
{
	assert(difficulty <= this->hash.size() && "The difficulty is above than hash length!");

	while (difficulty)
		if (this->hash[--difficulty] != '0')
			return false;

	return true;
}

void bcc::block::mine_block(uint32_t difficulty)
{
	do
	{
		this->nonce++;
		this->calculate_hash();
	}
	while (!this->check_hash(difficulty));

	std::cout << "Mined! Hash: " << this->hash << "\n";
}

void bcc::block::calculate_hash()
{
	this->hash = sha256(this->to_string());
}

std::string bcc::block::to_string() const
{
	std::stringstream ss;
	ss
		<< this->index << ":"
		<< this->timestamp << ":"
		<< this->tree->get_hash_top() << ":"
		<< this->nonce << ":"
		<< this->prev_hash;

	return ss.str();
}
