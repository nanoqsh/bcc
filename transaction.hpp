#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>
#include <sstream>


class transaction
{
private:
	std::string sender;
	std::string recipient;
	std::string message;

	transaction & operator=(const transaction & other) {}

public:
	explicit transaction(
		const std::string & sender,
		const std::string & recipient,
		const std::string & message
		);
	transaction(const transaction & other);
	virtual ~transaction();
	std::string to_string() const;

};

#endif // TRANSACTION_H_
