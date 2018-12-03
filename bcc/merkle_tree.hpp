#ifndef MERKLE_TREE_H_
#define MERKLE_TREE_H_

#include <vector>
#include <string>
#include <memory>
#include "merkle_node.hpp"


namespace bcc
{
	/*
	 * The merkle tree is binary tree of hashes
	 * Merkle tree's root consists of all included hashes
	 *
	 *        H   (H = hash(h ++ h))
	 *      /   \
	 *     h     h  (h = hash(l ++ l))
	 *    / \   / \
	 *   l   l l   l  (l is a raw value)
	 *
	 * where:
	 *		"++" is string concatenation
	 *		hash is SHA256 function
	 *
	 */
	class merkle_tree
	{
	private:
		std::shared_ptr<merkle_node> root;

		merkle_tree(const merkle_tree & other) {}
		merkle_tree & operator=(const merkle_tree & other) { return * this; }

		std::shared_ptr<merkle_node> build(std::vector<std::string> values);

	public:
		explicit merkle_tree(std::vector<std::string> values);
		virtual ~merkle_tree();
		std::string get_hash_top() const;
		const std::shared_ptr<merkle_node> get_root() const;

	};
}

#endif // MERKLE_TREE_H_
