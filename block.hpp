#ifndef BLOCK_H_
#define BLOCK_H_

#include <cstdint>
#include <iostream>
#include <ctime>
#include <assert.h>
#include <sstream>
#include <vector>
#include <memory>
#include "sha256/sha256.hpp"
#include "transaction.hpp"
#include "merkle_node.hpp"
#include "merkle_tree.hpp"


class block
{
private:
	uint32_t index;
	uint64_t nonce;
	std::shared_ptr<merkle_tree> tree;
	std::string hash;
	time_t timestamp;

	block & operator=(const block & other) const {}

	void calculate_hash();

public:
	std::string prev_hash;

	explicit block(uint32_t index, std::vector<transaction> transactions);
	block(const block & other);
	virtual ~block();

	std::string get_hash() const;
	std::string to_string() const;
	bool check_hash(uint32_t difficulty);
	void mine_block(uint32_t difficulty);
};

#endif // BLOCK_H_
