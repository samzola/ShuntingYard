#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(char*);
  ~Node();
  void setNext(Node*);
  void setFront(Node*);
  void setBack(Node*);
  Node* getNext();
  Node* getFront();
  Node* getBack();
  bool isFront();
  bool isBack();
  char* getOp();
 private:
  Node* next;
  Node* front;
  Node* back;
  char* op;
};

#endif
