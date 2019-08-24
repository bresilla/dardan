#include "block.h"

//constructor
Block::Block(int idx, Transaction d, size_t prevHash){
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

//private functions
size_t Block::generateHash(){
    std::hash<std::string> hash1;
    std::hash<std::string> hash2;
}
