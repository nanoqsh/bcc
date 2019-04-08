#ifndef BLOCKCHAIN_H_
#define BLOCKCHAIN_H_

#include <cstdint>
#include <vector>
#include "block.hpp"
#include "transaction.hpp"


namespace bcc
{
	class blockchain
	{
	private:
		uint32_t difficulty;
		std::vector<block> chain;

		// Private copy constructor
		blockchain(const blockchain & other) {}

		// Private assignment operator
		blockchain & operator=(const blockchain & other) { return * this; }

		const block & get_last_block() const;

	public:
		explicit blockchain(uint32_t difficulty);
		virtual ~blockchain();

		// Add block to blockchain
		// It will mine block for adjusted difficulty
		void add_block(block & bl);

	};
}

#endif // BLOCKCHAIN_H_
