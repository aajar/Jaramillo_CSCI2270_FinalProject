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

void HashTable::insertMovie(string title, int year)
{
    
    
    
    int sum = 0;
    for(int i = 1; i < title.length(); i++)
    {
        sum = sum + title[i];
    }
    sum = sum % tableSize;
    if(hashTable[sum].year == 0)
    {
        hashTable[sum] = Movie(title, year);
        //cout << sum << endl;
        //cout << hashTable[sum].title << endl;
        
    }else{
        Entry* current;
        current = &hashTable[sum];
        if (current -> next == NULL)
        {
            current -> next = new Entry(title, year);
            //cout << sum << endl;
            //cout << hashTable[sum].next -> title << endl;
        } else{
            while(current -> next -> title != "")
            {
                current = current -> next;
            }
            current -> next = new Entry(title, year);
            // cout << sum << endl;
            //cout << hashTable[sum].next -> title << endl;
        }
    }
    
}
void HashTable::findMovie(string title)
{
    Entry* userMovie = NULL;
    Entry* current = NULL;
    int sum = 0;
    for(int i = 1; i < title.length(); i++)
    {
        sum = sum + title[i];
    }
    sum = sum % tableSize;
    if(hashTable[sum].title.length() > 0)
    {
        if(hashTable[sum].title == title)
        {
            userMovie = &hashTable[sum];
        }else{
            while(current -> title.length() > 0)
            {
                if(current -> title == title)
                {
                    userMovie = current;
                }else{
                    current = current -> next;
                }
            }
        }
    }
    if(userMovie == NULL)
    {
        cout << "not found" << endl;
    } else {
        cout << sum << ":" << userMovie -> title << ":" << userMovie -> year << endl;
    }
    
}
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
    Movie* current;
    current = &hashTable[i];
    while(current -> next != NULL)
    {
        // hashTable[i].length;
    }
}
void HashTable::printInventory()
{
    int i = 0;
    int x = 0;
    Movie* checker = NULL;
    while(i < tableSize)
    {
        
        
        if(hashTable[i].next == NULL && hashTable[i].year > 0)
        {
            cout << i << ":" << hashTable[i].title << ":" << hashTable[i].year << endl;
            checker = &hashTable[i];
            i++;
        }else if( hashTable[i].next != NULL && hashTable[i].year > 0){
            
            checker = &hashTable[i];
            Movie* current = &hashTable[i];
            while(current ->next != NULL)
            {
                x++;
                current = current -> next;
            }
            x++;
            Movie* list = new Movie[x];
            current = &hashTable[i];
            int count = 0;
            while(current -> next != NULL)
            {
                list[count] = *current;
                current = current -> next;
                count++;
                
            }
            list[count] = *current;
            for(int vv = 0; vv < x; vv++)
            {
                list = sort(list, x, i);
            }
            delete[] list;
            
            
            
        }
        
        i++;
    }
    
    
    
    if(checker == NULL)
    {
        cout << "empty" << endl;
    }
}