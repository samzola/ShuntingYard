#include <iostream>
#include "node.h"
#include "list.h"
#include "function.h"

Node::Node(char* setOp) { //constructor
  next = NULL;
  front = NULL;
  back = NULL;
  op = setOp;
}

Node::~Node() {} //destructor

void Node::setNext(Node* newnext) { //sets next node
  next = newnext;
}

void Node::setFront(Node* newfront) {  //sets front node
  front = newfront;
}

void Node::setBack(Node* newback) { //sets back node
  back = newback;
}

Node* Node::getNext() { //returns next node
  return next;
}

Node* Node::getFront() { //returns front node
  return front;
}

Node* Node::getBack() { //returns back node
  return back;
}

bool Node::isFront() { //tests if there is a node in front
  if (front != NULL) {
    return true;
  }
  else {
    return false;
  }
}

bool Node::isBack() { //tests if there is a node in back
  if (back != NULL) {
    return true;
  }
  else {
    return false;
  }
}

char* Node::getOp() { //returns operator
  return op;
}
