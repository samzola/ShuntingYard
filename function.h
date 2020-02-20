#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;

class Function {
 public:
  Function();
  ~Function();
  List* getQueue();
  void setQueue(List*);
  void makePostfix();
  void makeTree(List*);
  void infixTool(Node*);
  void postfixTool(Node*);
  void prefixTool(Node*);
 private:
  bool isOperator(char);
  int precedence(char);
  bool playing;
  List* stack;
  List* operatorStack;
  List* expressionQueue;
};

#endif
