#include "transaction.hpp"


bcc::transaction::transaction(
	uint32_t sender,
	uint32_t recipient,
	const std::string & message
	) :
	sender(sender),
	recipient(recipient),
	message(message)
{
}

bcc::transaction::transaction(const transaction & other) :
	sender(other.sender),
	recipient(other.recipient),
	message(other.message)
{
}

bcc::transaction::~transaction() {}

std::string bcc::transaction::to_string() const
{
	std::stringstream ss;
	ss
		<< this->sender << ":"
		<< this->recipient << ":"
		<< this->message;

	return ss.str();
}
