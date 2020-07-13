#pragma once
#include <iostream>
#include <limits.h>
using namespace std;
class List;
class Node {
    
public:
   
    
    int val;
    Node* next;
    Node* prev;
    Node();
    Node(int, Node*, Node*);
    Node* getNext();
    Node* getPrev();
    int getVal();
    void setVal(int);
    void setNext(Node*);
    void setPrev(Node*);
    friend class DoublyLinkedList;


};