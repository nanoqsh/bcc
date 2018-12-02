
# Blockchain based chat

## Build
```
git clone https://github.com/nekosora/bcc.git
cd bcc
make
./blcc
```

## Example

```c++

using namespace bcc;

// Create a blockchain with difficulty == 3
blockchain bc(3);

// Create a block with index == 1
// and message "Curiosity killed the cat"
block b(1, { transaction(3, 2, "Curiosity killed the cat") });

// Mine block to blockchain
bc.add_block(b);

```
