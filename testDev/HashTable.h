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
    string date;
    Entry* next;
    
    Entry(){
        date = "0";
        next = NULL;
    };
    
    Entry(string in_title, payment_address in_address, hash_digest userfileHash, string in_date)
    {
        name = in_title;
        address = in_address;
        fileHash = userfileHash;
        date = in_date;
        next = NULL;
        
    }
    
};

class HashTable
{
public:
    HashTable(int);
    ~HashTable();
    void insertEntry(Entry);
    void findEntry(string);
    void deleteEntry(string);
    void printEntries();
    //void sort(int i);
    //void shuffle(Entry*, Entry*);
protected:
private:
    Entry* hashTable;
    int tableSize;
    
};









#endif /* defined(__testDev__HashTable__) */
