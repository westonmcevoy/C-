// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    node* temp = table[index];
    
    //TODO: Search the list at that specific index and return the node if found
    while((temp!=NULL) && (temp->key != key)){
        temp = temp->next;
    }
    if(temp==NULL){
        return NULL;
    }
    else{
        return temp;
    }
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        node* insert = new node;
        insert->key = key;
        insert->next = NULL;
        
        int nind = hashFunction(key);
        node* temp;
        node* prev;
        
        if(!table[nind]){
            table[nind] = insert;
            return true;
        }
        else{
            temp = table[nind];
            while(temp){
                prev = temp;
                temp = temp->next;
            }
            prev->next = insert;
            return true;
        }
    }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    node * temp;
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        temp = table[i];
        while(temp){
             cout << temp->key << endl;
             temp = temp->next;
        }
    }

 }
