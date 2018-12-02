#include "blockchain.hpp"


bcc::blockchain::blockchain()
	: difficulty(3)
{
	std::vector<transaction> genesis_transactions = {
		transaction(0, 0, "Genesis Block")
		};

	block genesis_block = block(0, genesis_transactions);
	genesis_block.mine_block(0);
	this->chain.push_back(genesis_block);
}

bcc::blockchain::~blockchain() {}

void bcc::blockchain::add_block(block & bl)
{
	bl.prev_hash = this->get_last_block().get_hash();
	bl.mine_block(this->difficulty);
	this->chain.push_back(bl);
}

const bcc::block & bcc::blockchain::get_last_block() const
{
	assert(!this->chain.empty() && "Blockchain is empty");

	return this->chain.back();
}
