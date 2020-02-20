#include "list.h"
#include "node.h"

List::List() {
  head = NULL;
  tail = NULL;
}

List::~List() {}

void List::push(Node* n) { //add as first node
  if (empty() == true) { //if list is empty
    head = n; //add node as only node
    tail = n;
  }
  else { //if not empty
    n->setNext(head); //make node the first
    head = n; //push back head
  }
}

void List::pop() { //remove first node
  if (empty() != true) { //if not empty
    Node* temp = head; //make a temporary node to keep track of the first node
    head = head->getNext(); //replace head with second node
    delete temp; //delete first node
  }
  else if (head == 0) { //if head is null
    head = 0; //set head and tail to null
    tail = 0;
  }
  else {
    cout << endl;
  }
}

void List::remove() { //removes first node
  if (empty() != true) { //if not empty
    head = head->getNext(); //replace first node with second node
  }
  else if (head == 0) { //if head is null
    head = 0; //set head and tail to null
    tail = 0;
  }
  else {
    cout << endl;
  }
}

Node* List::peek() { //returns first node
  return head;
}

void List::enqueue(Node* n) { //add node to end of list
  if (empty() == true) { //if list is empty
    head = n; //set node as only node in list
    tail = n;
  }
  else { //if not empty
    tail->setNext(n); //add another node after the tail node
    tail = n; //set it to the inputted node
  }
}

void List::dequeue() { //remove from beginning of list
  if (empty() != true) { //if not empty
    Node* temp = head; //remove first node
    head = head->getNext();
    delete temp;
  }
  else if (empty() == true) { //if list is empty
    head = 0; //set head and tail to null
    tail = 0;
  }
  else {
    cout << endl;
  }
}

bool List::empty() { //tests if the list is empty or not
  if (head == 0) { //if head is null
    tail = 0; //make tail null
    return true; //return as empty
  }
  else { //if head isnt null
    return false; //return as not empty
  }
}

Node* getHead() { //returns head node
  return head;
}

Node* getTail() { //returns tail node
  return tail;
}
