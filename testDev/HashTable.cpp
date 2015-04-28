//
//  HashTable.cpp
//  testDev
//
//  Created by ipaperweight on 4/24/15.
//  Copyright (c) 2015 AaronJaramillo. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "HashTable.h"
#include <vector>



using namespace std;
/*
 
 
 
 
 */
HashTable::HashTable(int size)
{
    hashTable = new Entry[size];
    tableSize = size;
}

HashTable::~HashTable()
{
    hashTable = NULL;
    delete hashTable;
}
/*
 void HashTable::insertEntry(Entry newFile)

 Takes an Entry struct and sum hashes it, then adds it to the appropriate index in the hash table, using chaining for collision resolution. 
 
 Pre-Condition: a HashTable constructed. and the Entry struct already constructed. 
 Post: An Entry node added to the hash table.
 
 
 
 */
void HashTable::insertEntry(Entry newFile)
{
    
    
    
    int sum = 0;
    for(int i = 1; i < newFile.name.length(); i++)
    {
        sum = sum + newFile.name[i];
    }
    sum = sum % tableSize;
    if(hashTable[sum].date == "0")
    {
        hashTable[sum] = newFile;
        //cout << sum << endl;
        //cout << hashTable[sum].title << endl;
        
    }else{
        Entry* current;
        current = &hashTable[sum];
        if (current -> next == NULL)
        {
            current -> next = &newFile;
            //cout << sum << endl;
            //cout << hashTable[sum].next -> title << endl;
        } else{
            while(current -> next -> name != "")
            {
                current = current -> next;
            }
            current -> next = &newFile;
            // cout << sum << endl;
            //cout << hashTable[sum].next -> title << endl;
        }
    }
    
}
/*
 void HashTable::findEntry(string name)

 Takes a string and searches through the hash table and the appropriate linked lists to find an entry with that string as its 'name'. 
 
 Pre: A constructed Hash Table. Handles Not Found.
 
 
 
 */
void HashTable::findEntry(string name)
{
    Entry* userEntry = NULL;
    Entry* current = NULL;
    int sum = 0;
    for(int i = 1; i < name.length(); i++)
    {
        sum = sum + name[i];
    }
    sum = sum % tableSize;
    if(hashTable[sum].name.length() > 0)
    {
        if(hashTable[sum].name == name)
        {
            userEntry = &hashTable[sum];
        }else{
            while(current -> name.length() > 0)
            {
                if(current -> name == name)
                {
                    userEntry = current;
                }else{
                    current = current -> next;
                }
            }
        }
    }
    if(userEntry == NULL)
    {
        cout << "not found" << endl;
    } else {
        cout << sum << "|" << userEntry -> name << endl;
        cout << " |" << userEntry -> date << endl;
        string displayAddy = userEntry -> address.encoded();
        cout << " |" << displayAddy << endl;
    }
    
}

/*
 void HashTable::insertDelete(Entry newFile)
 
 Takes an Entry struct and sum hashes it, then adds it to the appropriate index in the hash table, using chaining for collision resolution.
 
 Pre-Condition: a HashTable constructed. and the Entry struct already constructed.
 Post: An Entry node added to the hash table.
 
 
 
 */
void HashTable::deleteEntry(string name)
{
    Entry* userEntry = NULL;
    Entry* current = NULL;
    int sum = 0;
    for(int i = 1; i < name.length(); i++)
    {
        sum = sum + name[i];
    }
    sum = sum % tableSize;
    if(hashTable[sum].name.length() > 0)
    {
        if(hashTable[sum].name == name)
        {
            userEntry = &hashTable[sum];
        }else{
            while(current -> name.length() > 0)
            {
                if(current -> name == name)
                {
                    userEntry = current;
                }else{
                    current = current -> next;
                }
            }
        }
    }
    if(userEntry -> name == name)
    {
        if (userEntry -> next == NULL)
        {
           delete &userEntry;
        }else {
            userEntry = userEntry -> next;
        }
    }else{
        Entry* current;
        Entry* previous = NULL;
        current = &hashTable[sum];
        while (current -> name != name)
        {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        delete &current;
        
    }
    
    
}



/*
 void HashTable::printEntries()

 This Function prints out all of the Entries in the Hash Tables by searching through the indecies and appropriate chains. Handles empty.
 
 Pre: A constructed hash table
 
 
 
 */
void HashTable::printEntries()
{
    int i = 0;
    Entry* checker = NULL;
    while(i < tableSize)
    {
        
        
        if(hashTable[i].next == NULL && hashTable[i].date != "0")
        {
            cout << i << ":" << hashTable[i].name << ":" << hashTable[i].date << endl;
            checker = &hashTable[i];
            i++;
        }else if( hashTable[i].next != NULL && hashTable[i].date != "0"){
            
            checker = &hashTable[i];
            Entry* current = &hashTable[i];
            while(current -> next != NULL)
            {
                cout << current -> name << endl;
                current = current -> next;
            }
            cout << current -> name << endl;
            
            
            
        }
        
        i++;
    }
    
    
    
    if(checker == NULL)
    {
        cout << "empty" << endl;
    }
}
