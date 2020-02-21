#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node { //node class
 public:
  Node(char*); //constructor, passes in a char
  ~Node(); //destructor
  void setNext(Node*); //sets next node
  void setFront(Node*); //sets front node
  void setBack(Node*); //sets back node
  Node* getNext(); //returns next node
  Node* getFront(); //returns front node
  Node* getBack(); //returns back node
  bool isFront(); //tests if there is a node in front
  bool isBack(); //tests if there is a node in back
  char* getOp(); //returns operator
 private:
  Node* next;
  Node* front;
  Node* back;
  char* op;
};

#endif
