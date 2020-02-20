#include <iostream>
#include "node.h"

Node::Node(char* setOp) {
  next = NULL;
  front = NULL;
  back = NULL;
  op = setOp;
}

Node::~Node() {}

void Node::setNext(Node* newnext) {
  next = newnext;
}

void Node::setFront(Node* newfront) {
  front = newfront;
}

void Node::setBack(Node* newback) {
  back = newback;
}

Node* Node::getNext() {
  reutrn next;
}

Node* Node::getFront() {
  return front;
}

Node* Node::getBack() {
  return back;
}

bool Node::isFront() {
  if (front != NULL) {
    return true;
  }
  else {
    return false;
  }
}

bool Node::isBack() {
  if (back != NULL) {
    return true;
  }
  else {
    return false;
  }
}

char* Noe::getOp() {
  return op;
}
