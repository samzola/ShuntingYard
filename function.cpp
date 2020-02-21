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

List* Function::getQueue() { //returns queue
  return expressionQueue;
}

void Function::setQueue(List* newqueue) { //sets queue
  expressionQueue = newqueue;
}

void Function::makePostfix() { //CREDIT: Tejash Panda
  	List* stack = new List();
	List* operatorStack = new List();

	//run through expressionQueue
	while (expressionQueue->empty() != true) {
		char* headOp = expressionQueue->getHead()->getOp();//sets variable headOp eaqual to the op at head
		if (!isOperator(*headOp)) {//if the first char in the char[] is not a operator then ...
			Node* newNode = new Node(headOp);//push the head to the stack
			stack->push(newNode);
			expressionQueue->dequeue();
		}
		else {//if it is an operator
			if (*headOp == '(') {//if it is a (
				Node* newNode = new Node(headOp);//push it straight to the operatorStack
				operatorStack->push(newNode);
				expressionQueue->dequeue();
			}
			else if(*headOp != ')') {//if it is not a end perenthases
				int pred = precedence(*headOp);//calc precedence of the operator
				if (operatorStack->peek() != NULL) {//if there is stuff in the operator stack
					if (pred != 1) {//as long as the prededence is not 1
						while(operatorStack->peek() != NULL && precedence(*operatorStack->peek()->getOp()) > pred) {//while there is not nothing in the operatorStack and the prededence of the top of the opperator stack is more than the incoming operator...
							//push the top of the operator stack to the stack
							Node* newNode = new Node(operatorStack->peek()->getOp());
							stack->push(newNode);
							operatorStack->pop();
						}
						//push the incoming operator to the stack
						Node* newNode = new Node(headOp);
						operatorStack->push(newNode);
						expressionQueue->dequeue();
					}
					else {//if eaqual to 1 print this message
						cout << "You entered an invalid operator" << endl;
						return;
					}
				}
				else {
					//if there is nothing in the operator stack push straight to the stack
					Node* newNode = new Node(headOp);
					operatorStack->push(newNode);
					expressionQueue->dequeue();
				}
			}
			else {//if it is a end perentheses
				while (*operatorStack->peek()->getOp() != '(') {//while there isnt a ( at the top of the operator stack then...
					//push the items at the top of the operatior stack to the stack
					Node* newNode = new Node(operatorStack->peek()->getOp());
					stack->push(newNode);
					operatorStack->pop();
				}
				//get rid of the ( and )
				expressionQueue->dequeue();
				operatorStack->pop();
			}
		}
	}
	while (operatorStack->empty() != true) {//while the operator stack is not empty
		//push items from the top of the operator stack to the stack
		Node* newNode = new Node(operatorStack->peek()->getOp());
		stack->push(newNode);
		operatorStack->pop();
	}
	Node* current = stack->getHead();//set current to the head of stack
	List* expressionQueue = new List();//reintialize the list
	while (0 != current) {//while the current node is not NULL
		//push the current node to the expressionQueue
		Node* newNode = new Node(current->getOp());
		expressionQueue->push(newNode);
		current = current->getNext();
	}
	makeTree(expressionQueue);//make the tree
}

void Function::makeTree(List* input) { //CREDIT: Tejash Panda
  List* tree = new List();
  while (input->empty() != true) { //while input isn't empty
    if (isdigit(*input->peek()->getOp())) { //if it is an operator
      Node* filler = new Node(input->peek()->getOp());
      tree->push(filler); //add operator to tree
      input->dequeue(); //remove from input
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
    cout << "Do you want the output to be infix, postfix, or prefix?" << endl; //ask how user wants output
    char *choice = new char[10];
    cin.getline(choice, 10, '\n'); //read in choice
    if (strcmp(choice, "infix") == 0) { //if they enter infix
      infixTool(tree->peek()); //print out infix
      cout << endl;
      playing = false;
    }
    else if (strcmp(choice, "postfix") == 0) { //if they enter postfix
      postfixTool(tree->peek()); //print out postfix
      playing = false;
    }
    else if (strcmp(choice, "prefix") == 0) { //if they enter prefix
      prefixTool(tree->peek()); //print out prefix
      playing = false;
    }
    else {
      cout << "Please enter prefix, postfix, or infix." << endl;
    }
  }
}

void Function::infixTool(Node* binTree) { //for printing infix
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

void Function::postfixTool(Node* binTree) { //for printing postfix
  if (binTree->isBack()) { //if tree has a back
    postfixTool(binTree->getBack()); //recursively call for back
  }
  if (binTree->isFront()) { //if tree has a front
    postfixTool(binTree->getFront()); //recursively call for front
  }
  cout << binTree->getOp() << " "; //print
}

void Function::prefixTool(Node* binTree) { //for printing prefix
  cout << binTree->getOp() << " ";
  if (binTree->getBack() != NULL) { //if back isnt null
    prefixTool(binTree->getBack()); //recursively call for back
  }
  if (binTree->getFront() != NULL) { //if front isnt null
    prefixTool(binTree->getFront()); //recursively call for front
  }
}

bool Function::isOperator(char op) { //determines if it is a valid operator
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

int Function::precedence(char op) { //determines precedence
  switch(op) {
  case '+': return 2;
  case '-': return 2;
  case '*': return 3;
  case '/': return 3;
  case '^': return 4;
   default: return 0;
  }
}
