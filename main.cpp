/*
 * Author: Sam Zola
 * Date: 2/20/20
 * Program: This program allows the user to enter an expression and convert it to prefix, postfix, or infix using the Shunting Yard algorithm.
 */

#include <iostream>
#include "function.h"
#include "list.h"
#include "node.h"

using namespace std;

int main() {
  Function* translator = new Function(); //create new function
  cout << "Enter your expression here:" << endl; //have user enter expression
  char *input = new char[30]; //keeps track of input
  cin.getline(input, 30, '\n'); //read in input
  char *token = strtok(input, " "); //convert input into tokens for each number/operator
  List* newList = new List();
  while (token != NULL) { //if not through whole input
    Node* newNode = new Node(token); //make a node with the token
    newList->enqueue(newNode); //put node into queue
    token = strtok(NULL, " "); //make next token with next number/operator from input
  }
  translator->setQueue(newList); //translate
  translator->makePostfix(); //turn it into postfix
}
