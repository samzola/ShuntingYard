#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class List {
 public:
  List();
  ~List();
  //stack
  void push(Node*);
  void pop();
  Node* peek();
  void remove();
  //queue
  void enqueue(Node*);
  void dequeue();
  bool empty();
  Node* getHead();
  Node* getTail();
 private:
  Node* head;
  Node* tail;
};

#endif
