//
//  main.cpp
//  testDev
//
//  Created by ipaperweight on 4/20/15.
//  Copyright (c) 2015 AaronJaramillo. All rights reserved.
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


using namespace std;
using namespace bc;
//using namespace bc::client;
//using namespace bc::network;
using namespace bc::explorer;
using namespace bc::explorer::commands;
using namespace bc::explorer::primitives;

int main(int argc, const char * argv[]) {
    HashTable fileTable(10);
    int menuChoice = 0;
    
    while(menuChoice < 5)
    {
        menuChoice = menuChooser();

        if(menuChoice == 1)
        {
            //string filename;
            //cout << "Enter a File Name" << endl;
            //getline(cin, filename);
            string name;
            cout << "Go to http://hash.online-convert.com/sha256-generator and generate a hash of your file, then enter the files hash" << endl;
            string enteredHash;
            getline(cin, enteredHash);
            data_chunk hash = decode_hex(enteredHash);
            cout << "Enter a File Nickname" << endl;
            cin.ignore(1000, '\n');
            getline(cin, name);
            payment_address fileAddress;
            cout << "Enter the date" << endl;
            string date;
            getline(cin, date);
            //data_chunk fileByte = readFileBytes(filename);
            data_chunk filehash = hash;
            hash_digest newhash = fileHasher(filehash);

            fileAddress = HashtoAddress(hash);
            Entry newFile(name, fileAddress, newhash, date);
            fileTable.insertEntry(newFile);
            cout << newFile.address.encoded() << endl;
            
        }else if(menuChoice == 2){
            string searchName;
            cout << "Enter a File Name to Search" << endl;
            cin.ignore(1000, '\n');
            getline(cin, searchName);
            fileTable.findEntry(searchName);
            
            
        }else if(menuChoice == 3){
            fileTable.printEntries();
        }else if(menuChoice == 4){
            string name;
            cin.ignore(1000, '\n');
            cout << "Enter the name of an entry to delete" << endl;
            getline(cin, name);
            fileTable.deleteEntry(name);
        }
        
    }

    
    
    

    /*
     ==================Attempt================================
     === failed attempt to create an OP_Return transaction====
     === The ideal method to attach a hash to the blockchain==
     =========================================================
     
    data_chunk data = decode_hex("Aaron Jaramillo");
    data_slice newData = base16(data);
    short_hash hashData = ripemd160_hash(newData);
    auto tokens = "dup hash160 [ base16(ripemd160_hash(data)) ] equalverify checksig";
    script_type script;
    script.
    
    const auto serialized_script = save_script(embeded_script);
    const auto ripemd160 = ripemd160_hash(serialized_script);
    
    const address pay_address(1, ripemd160);
    
    cout << pay_address << endl;
    
    
    ifstream file;
    file.open("file.txt");
    
    hash_digest fileHash = sha256_hash(file);
    string hash = encode_hex(fileHash);
     ************************************************************
     *********** Trouble connecting to the Obelisk server *******
     *********** which is neccesary to automattically get *******
     *********** unspent outputs for the newTX inputs     *******
     ************************************************************
     
    connection_type connection;
    connection.server = primitives::uri("tcp://obelisk.airbitz.co:9091");
    connection.retries = uint8_t(5);
    connection.wait = chrono::milliseconds(2000);
    obelisk_client obelisk(connection);
    if(!obelisk.connect(connection))
    {
        cout<< "failed to connect to Obelisk" << endl;
        
    }
    ec_secret secret;
    bool success = decode_base16(secret, "038109007313a5807b2eccc082c8c3fbb988a973cacf1a7df9ce725c31b14776");
    assert(success);
    
    ec_point public_key = secret_to_public_key(secret);
    payment_address payaddr;
    set_public_key(payaddr, public_key);
    
   // history_row previousTransaction;
   
    function<void (const history_list&)> fetch_history_handler = fetchHandler;
    
    function<void (const std::error_code&)> error_handler;
    
    
    obelisk.get_codec()->fetch_history(error_handler, fetch_history_handler, payaddr);
    
    
 
    
    
    
    
    
    hash_digest hash;
    const data_chunk& data = base16("satoshi Nokamoto");
    hash = sha256_hash(data);
    auto tokens = format(ADDRESS_EMBED_SCRIPT) % base16(ripemd160_hash(hash));
    const script embeded_script(split(tokens.str()));/Users/AaronJaramillo/Desktop/testDev/testDev/main.cpp
    
    const auto serialized_script = save_script(embeded_script);
    const auto ripemd160 = ripemd160_hash(serialized_script);
    
    const address pay_address(1, ripemd160);
    
    cout << pay_address << endl;
    
    
    
    
    system("bx seed");
    
    
   
    block_type blk = genesis_block();
    cout << encode_hex(hash_block_header(blk.header)) << endl;
    threadpool net_pool(2);
    //const auto connection = get_connection(*this);
    //fetch_address_history
    
    //create TX
    
    //create input by hash and index
    transaction_input_list inputs;
    transaction_input_type UTXO;
    //get last outputs
        //address to get them from
    
    ec_secret secret;
    bool success = decode_base16(secret, "038109007313a5807b2eccc082c8c3fbb988a973cacf1a7df9ce725c31b14776");
    assert(success);
    
    ec_point public_key = secret_to_public_key(secret);
    payment_address payaddr;
    set_public_key(payaddr, public_key);
    string address = "1MmPjzXJhLJjdA24iUWbGxYZYcfKYSjGCw"; //payaddr.encoded();
        //fetch history from bx shell
    
    string command = "bx fetch-history ";
    command = command + address;
    const char* com = command.c_str();
    cout << com << endl;
    cout << command << endl;
    system(com);
    
        //parse ostream for hash
    
    point_type inputHash;

    //cast_chunk<uint32_t>(aa35d87098dcb5ec27feb862e63854e1cfcb09607282d5077d9304e6d2b4c094);
    inputHash.index =
    UTXO.
    
    
    inputs.push_back(UTXO);

    
   
    

    input_point first;
    //create output
    transaction_output_list outputs;
    transaction_output_type Oput;
    //create script
    script_type returnScript;
    operation notarize;
    notarize.code = opcode::return_;
    returnScript.push_operation(notarize);
    //add script to output
    Oput.script = returnScript;
    Oput.value = 000000000000000000LLU;
    outputs.push_back(Oput);
    //sign transaction
    
    //hash transaction
    
    
    /// send transaction
    

    
    
    
    

    
    hash_digest last_output = 
    first.hash;
    
    first.index =
    
    UTXO.previous_output = ;

    UTXO.script = ;
    UTXO.sequence = ;
    
    
 
    
    
    
    tx.inputs = inputs;
    
  
    
    
 
    
    
    
    
    
    
    //payment_type pay;
    

    
    
    
    
    ec_secret secret;
    ec_point public_key = secret_to_public_key(secret);
    cout << encode_hex(public_key) << endl;
    payment_address address;
    set_public_key(address, public_key);
    string addr = address.encoded();
    
    //cout << address << endl;
    cout << addr << endl;
    
    //privateKey = ec_new(ec);

    
    
    
    
    
   // cout << &ec << endl;
     return 0;
     */
    return 0;
    
}