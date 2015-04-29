# Jaramillo_CSCI2270_FinalProject
CSCI2270 Final Project Repository

ShaNotary Project

Project Summary 

ShaNotary is a cryptographic proof-of-existence program using the bitcoin blockchain. ShaNotary takes the sha256 hash of a file and hashes it using ripemd160 and then encoded the resulting hash to a bitcoin address, once a transaction is sent to the address it is permenantly recorded on the blockchain. ShaNotary uses libbitcoin and libbitcoin-explorer for bitcoin hash functions. 

How to Run

to compile the code and its dependencies run in the command line 

    $g++ main.cpp helper.h helper.cpp HashTable.h HashTable.cpp $(pkg-config --cflags --libs libbitcoin)

1. First, Go to http://hash.online-convert.com/sha256-generator and generate a hash of your file, copy the hex          formatted hash. 

2. Follow the on screen menu to create a bitcoin address from the file hash. 

3. use libbitcoin command line command in a seperate terminal

        $bx address-validate <address> 
        
        to check that the address given is a valid bitcoin address. 

4. then send a small amount of bitcoin to the address(these coins are irretrivable). you can verify that your btc address recieved the transaction by loking the address up on blockchain.info. 

5. To prove the existence of a file on a certain date, generate the address using the same method and verify that the address exists and recieved a transaction on a certain date via blockchain.info 


Dependencies

This project uses the c++ library libbitcoin and libbitcoin-explorer; Building libbitcoin-explorer from source installs the libbitcoin library as well as the libbitcoin-explorer command line tools. 
go to https://github.com/libbitcoin/libbitcoin-explorer and follow the instructions in the readme for your specific machine. to install just the libbitcoin library go to https://github.com/libbitcoin/libbitcoin and follow the instructions in the read me for your specific machine. 



System Requirements



Open Issues/Bugs

The delete function in hashTable has an error causing the rogram to break.

using OP_RETURN is the optimal method for embedding data in the blockchain because it doesn't creat an unspendable output in the UTXO pool for miners. The function for connecting to obelisk is broken. 

the function to read in a file and hash it directly in the program is buggy so it is currently non functional.

