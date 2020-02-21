#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class List {
 public:
  List(); //constructor
  ~List(); //destructor
  //stack functions
  void push(Node*); //push into stack
  void pop(); //delete first from stack
  Node* peek(); //return first from stack
  void remove(); //remove first from stack without deleting
  //queue functions
  void enqueue(Node*); //add to front of queue
  void dequeue(); //remove from queue
  bool empty(); //checks if list is empty
  Node* getHead(); //returns first node
  Node* getTail(); //returns last node
 private:
  Node* head;
  Node* tail;
};

#endif
