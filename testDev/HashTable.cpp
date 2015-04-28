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
Movie* HashTable::sort(Movie* list, int x, int i)
{
    for (int j = 0; j < x; j++)
    {
        Movie* working = &list[j];
        if(working -> year == 0)
        {
            
        }else{
            for(int z = 0; z < x; z++)
            {
                string compare = list[z].title;
                int yearCheck = list[z].year;
                if(working -> title > compare && yearCheck != 0 && working -> year != 0)
                {
                    working = &list[z];
                }
            }
            cout << i << ":" << working -> title << ":" << working -> year << endl;
            for(int q = 0; q < x; q++)
            {
                if(working == &list[q])
                {
                    Movie empty = Movie();
                    list[q] = empty;
                }
            }
            
        }
        working = NULL;
        delete working;
    }
    
    
    
    return list;
}

void HashTable::deleteMovie(string title)
{
    int sum = 0;
    for(int i = 1; i < title.length(); i++)
    {
        sum = sum + title[i];
    }
    sum = sum % tableSize;
    if(hashTable[sum].title == title)
    {
        if (hashTable[sum].next == NULL)
        {
            hashTable[sum] = Movie();
        }else {
            hashTable[sum] = *hashTable[sum].next;
        }
    }else{
        Movie* current;
        Movie* previous = NULL;
        current = &hashTable[sum];
        while (current -> title != title)
        {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        delete &current;
        
    }
    
    
}

void HashTable::shuffle(Movie* a, Movie* b)
{
    //
}




void HashTable::sort(int i)
{
    Entry* current;
    current = &hashTable[i];
    while(current -> next != NULL)
    {
        // hashTable[i].length;
    }
}
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
