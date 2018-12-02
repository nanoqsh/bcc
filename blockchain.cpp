#include "blockchain.hpp"


blockchain::blockchain()
	: difficulty(3)
{
	std::vector<transaction> genesis_transactions = {
		transaction("0", "0", "Genesis Block") 
		};

	this->chain.push_back(block(0, genesis_transactions));
}

blockchain::~blockchain() {}

void blockchain::add_block(block & bl)
{
	bl.prev_hash = this->get_last_block().get_hash();
	bl.mine_block(this->difficulty);
	this->chain.push_back(bl);
}

const block & blockchain::get_last_block() const
{
	assert(!this->chain.empty() && "Blockchain is empty");

	return this->chain.back();
}
