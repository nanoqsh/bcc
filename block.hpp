#ifndef BLOCK_H_
#define BLOCK_H_

#include <cstdint>
#include <iostream>
#include <ctime>
#include <assert.h>
#include <sstream>
#include "sha256.hpp"


class block
{
private:
	uint32_t index;
	uint64_t nonce;
	std::string data;
	std::string hash;
	time_t timestamp;

	block & operator=(const block & other) const {}

	void calculate_hash();

public:
	std::string prev_hash;

	explicit block(uint32_t index, const std::string & data);
	block(const block & other);
	virtual ~block();

	std::string get_hash() const;
	bool check_hash(uint32_t difficulty);
	void mine_block(uint32_t difficulty);
};

#endif // BLOCK_H_
