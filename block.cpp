#include "block.hpp"


block::block(uint32_t index, const std::string & data) :
	index(index),
	data(data),
	nonce(-1)
{
	this->timestamp = std::time(nullptr);
}

block::block(const block & other) :
	index(other.index),
	nonce(other.nonce),
	data(other.data),
	hash(other.hash),
	timestamp(other.timestamp),
	prev_hash(other.prev_hash)
{
}

block::~block() {}

std::string block::get_hash() const
{
	return this->hash;
}

bool block::check_hash(uint32_t difficulty)
{
	assert(difficulty <= this->hash.size() && "The difficulty is above than hash length!");

	while (difficulty)
		if (this->hash[--difficulty] != '0')
			return false;

	return true;
}

void block::mine_block(uint32_t difficulty)
{
	do
	{
		this->nonce++;
		this->calculate_hash();
	}
	while (!this->check_hash(difficulty));

	std::cout << "Mined! Hash: " << this->hash << "\n";
}

void block::calculate_hash()
{
	std::stringstream ss;
	ss
		<< this->index
		<< this->timestamp
		<< this->data
		<< this->nonce
		<< this->prev_hash;

	this->hash = sha256(ss.str());
}
