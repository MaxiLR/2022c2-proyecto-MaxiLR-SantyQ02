#ifndef NODEWC_H
#define NODEWC_H

#include <iostream>
using namespace std;

template<class T>
class NodeWC{
private:
  T* data;
  NodeWC<T> *next;

public:
  NodeWC(T data){
    this->data = new T(data);
  }
  ~NodeWC(){
    delete next;
  }
  void setData(T data){
    *this->data = data;
  }
  T* getData(){
    return data;
  }
  void setNext(NodeWC<T>* next){
    this->next = next;
  }
  NodeWC<T>* getNext(){
    return next;
  }
};

#endif
