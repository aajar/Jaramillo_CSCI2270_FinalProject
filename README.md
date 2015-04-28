# Jaramillo_CSCI2270_FinalProject
CSCI2270 Final Project Repository

ShaNotary Project

Project Summary 

ShaNotary is a crypto graphic proof-of-existence program using the bitcoin blockchain. ShaNotary takes the sha256 hash of a file and hashes it using ripemd160 and then encoded the resulting hash to a bitcoin address, once a transaction is sent to the address it is permenantly recorded on the blockchain. ShaNotary uses libbitcoin and libbitcoin-explorer for bitcoin hash functions. 

How to Run

First, Follow the on screen menu to create a bitcoin address from the file hash. then send a small amount of bitcoin to the address(these coins are irretrivable). you can verify that your btc adress recieved the transaction by loking the address up on blockchain.info. 


Dependencies
This project uses the c++ library libbitcoin and libbitcoin-explorer; Building libbitcoin-explorer from source installs the libbitcoin library as well as the libbitcoin-explorer command line tools. 
go to https://github.com/libbitcoin/libbitcoin-explorer and follw the instructions in the readme for your specific machine. 



System Requirements



