#include <iostream>

#include "function.h"
#include "list.h"
#include "node.h"

using namespace std;

int main() {
  Function* infixTranslator = new Function();

  cout << "Enter your expression here" << endl;

  char *input = new char[30];
  cin.getline(input, 30, '\n');
  char *token = strtok(input, " ");
  List* newList = new List();
  while (token != NULL) {
    Node* newNode = new Node(token);
    newList->enqueue(newNode);
    token = strtok(NULL, " ");
  }
  infixTranslator->setQueue(newList);
  infixTranslator->makePostfix();
}
