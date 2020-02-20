#include <iostream>
#include <cstring>
#include "node.h"
#include "list.h"
#include "function.h"

using namespace std;

Function::Function() {
  List* expressionQueue = new List();
  playing = true;
}

Function::~Function() {}

List* Function::getQueue() {
  return expressionQueue;
}

void Function::setQueue(List* newqueue) {
  expressionQueue = newqueue;
}

void Function::makePostfix() {
  List* stack = new List();
  List* operatorStack = new List();

  while (expressionQueue->empty() != true) {
    char* headOp = expressionQueue->getHead()->getOp();
    if (!isOperator(*headOp)) {
      Node* newNode = new Node(headOp);
      stack->push(newNode);
      expressionQueue->dequeue();
    }
    else {
      if (*headOp == '(') {
	Node* newNode = new Node(headOp);
	operatorStack->push(newNode);
	expressionQueue->dequeue();
      }
      else if (*headOp != ')') {
	int pred = precedence(*headOp);
	if (operatorStack->peek() != NULL) {
	  if (pred != 1) {
	    while (operatorStack->peek() != NULL && precedence(*operatorStack->peek()->getOp()) > pred) {
	      Node* newNode = new Node(operatorStack->peek()->getOp());
	      stack->push(newNode);
	      operatorStack->pop();
	    }
	  }
	    else {
	      cout << "Invalid operator" << endl;
	      return;
	    }
	  }
	  else {
	    Node* newNode = new Node(headOp);
	    operatorStack->push(newNode);
	    expressionQueue->dequeue();
	  }
	}
	else {
	while (*operatorStack->peek()->getOp() != '(') {
	  Node* newNode = new Node(operatorStack->peek()->getOp());
	  stack->push(newNode);
	  operatorStack->pop();
	}
	expressionQueue->dequeue();
	operatorStack->pop();
      }
    }
  }
    while (operatorStack->empty() != true) {
      Node* newNode = new Node(operatorStack->peek()->getOp());
      stack->push(newNode);
      operatorStack->pop();
    }
    Node* current = stack->getHead();
    List* expressionQueue = new List();
    while (0 != current) {
      Node* newNode = new Node(current->getOp());
      expressionQueue->push(newNode);
      current = current->getNext();
    }
    makeTree(expressionQueue);
}

void Function::makeTree(List* input) {
  List* tree = new List();
  while (input->empty() != true) {
    if (isdigit(*input->peek()->getOp())) {
      Node* filler = new Node(input->peek()->getOp());
      tree->push(filler);
      input->dequeue();
    }
    else {
      Node* currentNode = new Node(input->peek()->getOp());
      currentNode->setFront(tree->peek());
      tree->remove();
      currentNode->setBack(tree->peek());
      tree->remove();
      tree->push(currentNode);
      input->dequeue();
    }
  }
  while (playing == true) {
    cout << "Do you want the output to be infix, postfix, or prefix?" << endl;
    char *choice = new char[10];
    cin.getline(choice, 10, '\n');
    if (strcmp(choice, "infix") == 0) {
      infixTool(tree->peek());
      cout << endl;
      playing = false;
    }
    else if (strcmp(choice, "postfix") == 0) {
      postfixTool(tree->peek());
      playing = false;
    }
    else if (strcmp(choice, "prefix") == 0) {
      prefixTool(tree->peek());
      playing = false;
    }
    else {
      cout << "Please enter prefix, postfix, or infix." << endl;
    }
  }
}

void Function::infixTool(Node* binTree) {
  if (isOperator(*binTree->getOp())) {
    cout << "( ";
  }
  else if (binTree->getBack() != NULL) {
    infixTool(binTree->getBack());
  }
  else if (binTree->getFront() != NULL) {
    infixTool(binTree->getFront());
  }
  else if (isOperator(*binTree->getOp())) {
    cout << ") ";
  }
  else {
    cout << endl;
  }
  cout << binTree->getOp() << " ";
}

void Function::postfixTool(Node* binTree) {
  if (binTree->isBack()) {
    postfixTool(binTree->getBack());
  }
  if (binTree->isFront()) {
    postfixTool(binTree->getFront());
  }
  cout << binTree->getOp() << " ";
}

void Function::prefixTool(Node* binTree) {
  cout << binTree->getOp() << " ";
  if (binTree->getBack() != NULL) {
    prefixTool(binTree->getBack());
  }
  if (binTree->getFront() != NULL) {
    prefixTool(binTree->getFront());
  }
}

bool Function::isOperator(char op) {
  switch(op) {
  case '+': return true;
  case '-': return true;
  case '*': return true;
  case '/': return true;
  case '^': return true;
  case '(': return true;
  case ')': return true;
  default: return false;
  }
}

int Function::precedence(char op) {
  switch(op) {
  case '+': return 2;
  case '-': return 2;
  case '*': return 3;
  case '/': return 3;
  case '^': return 4;
   default: return 0;
  }
}
