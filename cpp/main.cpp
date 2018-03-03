#include <ctime>
#include <vector>
#include <string>

using namespace std;

//Transactionion data
struct Transaction{
    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;
};


//block class
class Block{
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();

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


//block chain
class BlockChain{
    private:
        Block createGenesisBlock();

    public:
        //public chain
        vector<Block> chain;

        //constructor
        BlockChain();

        //public functions
        void addBlock(Transaction data);
        void isChainValid();
};

