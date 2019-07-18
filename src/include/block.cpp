#include "block.hpp"

using namespace std;

//constructor
Block::Block(int idx, Transaction d, size_t prevHash){
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

//private functions
size_t Block::generateHash(){
    hash<string> hash1;
    hash<string> hash2;
}


