#include "transaction.hpp"


transaction::transaction(
	const std::string & sender,
	const std::string & recipient,
	const std::string & message
	) :
	sender(sender),
	recipient(recipient),
	message(message)
{
}

transaction::transaction(const transaction & other) :
	sender(other.sender),
	recipient(other.recipient),
	message(other.message)
{
}

transaction::~transaction() {}

std::string transaction::to_string() const
{
	std::stringstream ss;
	ss
		<< this->sender << ":"
		<< this->recipient << ":"
		<< this->message;

	return ss.str();
}
