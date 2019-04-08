#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>
#include <sstream>
#include <inttypes.h>


namespace bcc
{
	/*
	 * A transaction contains:
	 *		- sender ID
	 *		- recipient ID
	 *		- message text
	 */
	class transaction
	{
	private:
		uint32_t sender;
		uint32_t recipient;
		std::string message;

		transaction & operator=(const transaction & other) { return * this; }

	public:
		transaction(
			uint32_t sender,
			uint32_t recipient,
			const std::string & message
		);
		transaction(const transaction & other);
		virtual ~transaction();
		std::string to_string() const;

	};
}

#endif // TRANSACTION_H_
