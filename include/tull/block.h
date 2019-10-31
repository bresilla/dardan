#pragma once
#include <ctime>
#include <vector>
#include <string>

//Transactionion data
struct Transaction{
    double amount;
    std::string senderKey;
    std::string receiverKey;
    std::time_t timestamp;
};

//block class
class Block{
    private:
        int index;
        std::size_t blockHash;
        std::size_t previousHash;
        std::size_t generateHash();
    public:
        //constructor
        Block(int idx, Transaction d, size_t prevHash);
        //get original hash
        size_t getHash();
        //get previous hash
        size_t getPreviousHash();
        //Transactionion data
        Transaction data;
        //validate hash
        bool isHashValid();
};

//block chain
class BlockChain{
    private:
        Block createGenesisBlock();
    public:
        //public chain
        std::vector<Block> chain;
        //constructor
        BlockChain();
        //public functions
        void addBlock(Transaction data);
        void isChainValid();
};
