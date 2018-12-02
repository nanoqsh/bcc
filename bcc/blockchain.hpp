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

		blockchain(const blockchain & other) {}
		blockchain & operator=(const blockchain & other) const {}

		const block & get_last_block() const;

	public:
		blockchain();
		virtual ~blockchain();

		void add_block(block & bl);

	};
}

#endif // BLOCKCHAIN_H_
