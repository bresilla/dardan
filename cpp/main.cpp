#include <ctime>
#include <vector>
#include <string>

using namespace std;

//transaction data
struct Tact{
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
        Block(int idx, Tact d, size_t prevHash);

        //get original hash
        size_t getHash();

        //get previous hash
        size_t getPreviousHash();
        
        //transaction data
        Tact data;
        
        //validate hash
        bool isHashValid();
};


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
        

};