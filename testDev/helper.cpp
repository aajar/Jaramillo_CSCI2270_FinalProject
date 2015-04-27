//
//  helper.cpp
//  
//
//  Created by ipaperweight on 4/26/15.
//
//

#include "helper.h"
#incliude "HashTable.h"

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

void displayMenu()
{
    
    cout << "====Main Menu =====" << endl;
    cout << "1. Get Hashed Address" << endl;
    cout << "2. search saved hashes" << endl;
    cout << "3. show hash information" << endl;
    
}

int menuChooser()
{
    cout << "====Main Menu =====" << endl;
    cout << "1. Get Hashed Address" << endl;
    cout << "2. search saved hashes" << endl;
    cout << "3. show hash information" << endl;
    cout << "4. Exit" << endl;
    
    int menuChoice;
    cin >> menuChoice;
    return menuChoice;
}

payment_address HashtoAddress()
{

    data_chunk data = decode_hex("Aaron Jaramillo");
    hash_digest shaed = sha256_hash(data);
    payment_address hashAddy(uint8_t(1), ripemd160_hash(shaed));
    cout << hashAddy.encoded() << endl;
    
    return hashAddy;
}