CPP_FLAGS=-std=c++11
DIR=bcc
SHA_DIR=sha256


blcc: block.o blockchain.o transaction.o merkle_tree.o merkle_node.o sha256.o main.o
	g++ $^ -o blcc

block.o: $(DIR)/block.cpp $(DIR)/block.hpp $(DIR)/transaction.hpp $(DIR)/merkle_tree.hpp $(DIR)/merkle_node.hpp
	g++ $(CPP_FLAGS) -c $(DIR)/block.cpp

blockchain.o: $(DIR)/blockchain.cpp $(DIR)/blockchain.hpp $(DIR)/block.hpp $(DIR)/transaction.hpp
	g++ $(CPP_FLAGS) -c $(DIR)/blockchain.cpp

transaction.o: $(DIR)/transaction.cpp $(DIR)/transaction.hpp
	g++ $(CPP_FLAGS) -c $(DIR)/transaction.cpp

merkle_tree.o: $(DIR)/merkle_tree.cpp $(DIR)/merkle_tree.hpp $(DIR)/merkle_node.hpp
	g++ $(CPP_FLAGS) -c $(DIR)/merkle_tree.cpp

merkle_node.o: $(DIR)/merkle_node.cpp $(DIR)/merkle_node.hpp $(SHA_DIR)/sha256.hpp
	g++ $(CPP_FLAGS) -c $(DIR)/merkle_node.cpp

sha256.o: $(SHA_DIR)/sha256.cpp $(SHA_DIR)/sha256.hpp
	g++ $(CPP_FLAGS) -c $(SHA_DIR)/sha256.cpp

main.o: main.cpp $(DIR)/block.hpp $(DIR)/blockchain.hpp $(DIR)/transaction.hpp $(DIR)/merkle_tree.hpp $(DIR)/merkle_node.hpp
	g++ $(CPP_FLAGS) -c main.cpp

clear:
	rm -f *.o
