#include "block.hpp"


bcc::block::block(uint32_t index, std::vector<transaction> transactions) :
	index(index),
	transactions(transactions),
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
	transactions(other.transactions),
	prev_hash(other.prev_hash)
{
}

bcc::block::~block() {}

std::string bcc::block::get_hash() const
{
	return this->hash;
}

uint32_t bcc::block::get_index() const
{
	return this->index;
}

uint64_t bcc::block::get_nonce() const
{
	return this->nonce;
}

time_t bcc::block::get_timestamp() const
{
	return this->timestamp;
}

const std::vector<bcc::transaction> & bcc::block::get_transactions() const
{
	return this->transactions;
}

std::string bcc::block::get_prev_hash() const
{
	return this->prev_hash;
}

bool bcc::block::check_hash(uint32_t difficulty)
{
	assert(difficulty <= this->hash.size() && "The difficulty is above than hash length!");

	/*
	 * This code checks difficulty of hash
	 * Count zeros from begin string to difficulty
	 *
	 * "000abc3456"
	 *    ^         0?
	 *   ^          0?
	 *  ^           0?
	 * -> ok!
	 *
	 */
	while (difficulty)
		if (this->hash[--difficulty] != '0')
			return false;

	return true;
}

void bcc::block::mine_block(uint32_t difficulty)
{
	/*
	 * Mine the block while nonce doesn't give valid hash
	 */
	do
	{
		this->nonce++;
		this->calculate_hash();
	}
	while (!this->check_hash(difficulty));
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

std::string bcc::block::to_debug_string() const
{
	std::stringstream ss;
	ss
		<< "Index: " << this->index << "\n"
		<< "Timestamp: " << this->timestamp << "\n"
		<< "Merkle root: " << this->tree->get_hash_top() << "\n"
		<< "Nonce: " << this->nonce << "\n"
		<< "Hash: " << this->hash << "\n"
		<< "Prev hash: " << this->prev_hash;

	return ss.str();
}
