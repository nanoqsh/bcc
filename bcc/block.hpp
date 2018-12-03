#ifndef BLOCK_H_
#define BLOCK_H_

#include <cstdint>
#include <iostream>
#include <ctime>
#include <assert.h>
#include <sstream>
#include <vector>
#include <memory>
#include "../sha256/sha256.hpp"
#include "transaction.hpp"
#include "merkle_node.hpp"
#include "merkle_tree.hpp"


namespace bcc
{
	class block
	{
	private:
		uint32_t index;
		uint64_t nonce;
		std::shared_ptr<merkle_tree> tree;
		std::string hash;
		time_t timestamp;
		std::vector<transaction> transactions;

		// Private assignment operator
		block & operator=(const block & other) { return * this; }

		// Calculate SHA256 hash
		void calculate_hash();

	public:
		// Previous block hash
		std::string prev_hash;

		explicit block(uint32_t index, std::vector<transaction> transactions);
		block(const block & other);
		virtual ~block();

		// Getters
		std::string get_hash() const;
		uint32_t get_index() const;
		uint64_t get_nonce() const;
		time_t get_timestamp() const;
		const std::vector<transaction> & get_transactions() const;
		std::string get_prev_hash() const;

		// Check block hash for the appropriate difficulty
		bool check_hash(uint32_t difficulty);

		// Mine block while while nonce doesn't give valid hash
		void mine_block(uint32_t difficulty);

		// To strings for reading
		std::string to_string() const;
		std::string to_debug_string() const;
	};
}

#endif // BLOCK_H_
