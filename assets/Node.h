#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template<class T>
class Node{
private:
  T data;
  Node<T> *next;

public:
  Node(T data=0){
    this->data = data;
  }
  ~Node(){
    delete next;
  }
  void setData(T data){
    this->data = data;
  }
  T getData(){
    return data;
  }
  void setNext(Node<T>* next){
    this->next = next;
  }
  Node<T>* getNext(){
    return next;
  }
};

#endif
