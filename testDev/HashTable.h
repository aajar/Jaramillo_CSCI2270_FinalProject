//
//  HashTable.h
//  testDev
//
//  Created by ipaperweight on 4/24/15.
//  Copyright (c) 2015 AaronJaramillo. All rights reserved.
//

#ifndef __testDev__HashTable__
#define __testDev__HashTable__

#include <iostream>
#include <fstream>
#include <functional>
#include <sstream>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/client.hpp>
//#include <bitcoin/client/obelisk.hpp>
#include <bitcoin/explorer.hpp>
#include <bitcoin/bitcoin/network/network.hpp>
#include <bitcoin/explorer/define.hpp>
#include <bitcoin/explorer/primitives/address.hpp>
#include <bitcoin/explorer/primitives/script.hpp>
#include <bitcoin/explorer/define.hpp>
#include <bitcoin/explorer/primitives/base16.hpp>
#include <bitcoin/explorer/commands/fetch-history.hpp>
#include <bitcoin/explorer/commands/address-embed.hpp>
#include <bitcoin/explorer/utility.hpp>

//#include <wallet/wallet.hpp>

using namespace std;
using namespace bc;
//using namespace bc::client;
//using namespace bc::network;
using namespace bc::explorer;
using namespace bc::explorer::commands;
using namespace bc::explorer::primitives;


struct Entry{
    string name;
    payment_address address;
    hash_digest fileHash;
    std::string date;
    Entry *next;
    
    Entry(){
    };
    
    Entry(string in_title, payment_address address, hash_digest fileHash,string date)
    {        name = in_title;

        address = address;
        fileHash = fileHash;
        string = date;
        
    }
    
};

class HashTable
{
public:
    HashTable(int);
    ~HashTable();
    void insertMovie(std::string in_title, int year);
    void findMovie(std::string in_title);
    void deleteMovie(std::string in_title);
    void printInventory();
    void sort(int i);
    void shuffle(Entry*, Entry*);
    Movie* sort(Entry*, int, int);
protected:
private:
    Entry* hashTable;
    int tableSize;
    
};









#endif /* defined(__testDev__HashTable__) */
