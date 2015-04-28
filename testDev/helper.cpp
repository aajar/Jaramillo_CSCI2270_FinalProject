//
//  helper.cpp
//  
//
//  Created by ipaperweight on 4/26/15.
//
//

#include "helper.h"
#include "HashTable.h"

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


/*
 int menuChoose()
 
 Method displays the main menu to the user and returns the number
 they chose as an int.
 
 
 
 */
int menuChooser()
{
    cout << "====Main Menu =====" << endl;
    cout << "1. Get Hashed Address" << endl;
    cout << "2. Search saved hashes" << endl;
    cout << "3. Show all entries" << endl;
    cout << "4. Exit" << endl;
    
    int menuChoice;
    cin >> menuChoice;
    return menuChoice;
}
/*
 data_chunk readFileBytes(string name)

 Function to read in a file by byte (uint8_t) and into
 data_chunk, the libbitcoin equivelent of vector<uint8_t>.
 ===============
 !!!!Broken!!!!
 ===============
 
 
 */
data_chunk readFileBytes(string name)
{
    basic_ifstream<uint8_t> fl(name);
    
    uint8_t someByte;
    data_chunk fileChunk;
    while(!fl.eof())
    {
        fl >> someByte;
        data_chunk fileChunk(uint8_t someByte);
    }
    fl.close();
    return fileChunk;
}

hash_digest filehasher(data_chunk fileData)
{
    hash_digest shaed = sha256_hash(fileData);
    
    return shaed;
}
/*
 payment_address HashtoAddress(data_chunk fileByte);
 
 this FUnction takes a data_chunk and sha256 hashes it. 
 then passes a version type and ripemd160 hash of the previous hash into a payment_address class constructor, which then encodes it to a readable BTC address of the specified version type. 
 
 
 
 */
payment_address HashtoAddress(data_chunk fileByte)
{
    
    hash_digest shaed = sha256_hash(fileByte);
    payment_address hashAddy(uint8_t(1), ripemd160_hash(shaed));
    cout << hashAddy.encoded() << endl;
    
    return hashAddy;
}