#include "LinkedList.hpp"

using namespace std;


// Search for a specified key and return a pointer to that node
//MANDETORY_TODO: complete this function
// Given the key this function will find the node where the key is present
// If found it will return the node, else NULL
Node* LinkedList::searchList(int key) {
    Node* ptr = head;
    while(ptr){
      if(ptr->key == key){
        return(ptr);
      }
      ptr = ptr->next;
    }
    ptr = NULL;
    return ptr;
}


// Add a new node to the list
//MANDETORY_TODO: complete this function
// This function will add a node with newKey after the prev node in the linked list
// if prev is null insertion is to be made at head
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
    Node* A = new Node;
    A->key = newKey;
    A->next = head;
    head = A;
  }
  //general insertion
  else{
    Node* B = new Node;
    B->key = newKey;
    B->next = prev->next;
    prev->next = B;
  }
}


// OPTIONAL_TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values). Swap the Nodes
bool LinkedList::swapFirstAndLast()
{
  bool isSwapped = false;
  if(head==NULL){
    return isSwapped;
  }
  Node *temp = head;
  Node* ptr = head;
  Node* prev;
  while(ptr->next){
    prev = ptr;
    ptr = ptr->next;
  }
  ptr->next = head->next;
  prev->next = temp;
  temp->next = NULL;
  head = ptr;
  isSwapped = true;
  return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}
