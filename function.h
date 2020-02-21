#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;

class Function { //function class
 public:
  Function(); //constructor
  ~Function(); //destructor
  List* getQueue(); //returns queue
  void setQueue(List*); //sets queue
  void makePostfix(); //converts input to postfix
  void makeTree(List*); //makes a binary tree of the input
  void infixTool(Node*); //sets to infix
  void postfixTool(Node*); //sets to postfix
  void prefixTool(Node*); //sets to prefix
 private:
  bool isOperator(char); //tests if operator
  int precedence(char);
  bool playing;
  List* stack;
  List* operatorStack;
  List* expressionQueue;
};

#endif
