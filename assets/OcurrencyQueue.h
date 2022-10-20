#ifndef OCURRENCYQUEUE_H
#define OCURRENCYQUEUE_H

#include "HashMapWC.h"

template <class T> class OcurrencyQueue {
private:
  NodeWC<T> *first, *last;
  unsigned int Size;

public:
  OcurrencyQueue();
  ~OcurrencyQueue();
  void push(T data);
  T pull();
  void loadQueue(HashMapWC &HM);
  bool isEmpty();
  void printN(unsigned int n = 0);
};

template <class T> OcurrencyQueue<T>::OcurrencyQueue() {
  first = nullptr;
  last = nullptr;
  Size = 0;
}

template <class T> OcurrencyQueue<T>::~OcurrencyQueue() {
  while (!isEmpty()) {
    pull();
  }
  delete first;
  delete last;
}

template <class T> void OcurrencyQueue<T>::push(T data) {
  NodeWC<T> *auxNode = first, *newNode = new NodeWC<T>(data);
  newNode->setNext(nullptr);

  if (isEmpty()) {
    first = newNode;
    last = newNode;
    Size++;
    return;
  }

  if (newNode->getData()->getCounter() >= first->getData()->getCounter()) {
    newNode->setNext(first);
    first = newNode;
    Size++;
    return;
  }

  while (auxNode->getNext() != nullptr &&
         newNode->getData()->getCounter() <
             auxNode->getNext()->getData()->getCounter()) {
    auxNode = auxNode->getNext();
  }

  if (auxNode->getNext() == nullptr) {
    auxNode->setNext(newNode);
    last = newNode;
    Size++;
    return;
  }

  newNode->setNext(auxNode->getNext());
  auxNode->setNext(newNode);
  Size++;
}

template <class T> T OcurrencyQueue<T>::pull() {
  NodeWC<T> *toDelete = first;

  if (isEmpty())
    throw 400;

  T data = *first->getData();
  first = first->getNext();

  if (first == nullptr)
    last = nullptr;

  delete toDelete;
  return data;
}

template <class T> void OcurrencyQueue<T>::loadQueue(HashMapWC &HM) {
  for (unsigned int i = 0; i < HM.getSize(); i++) {
    NodeWC<HashEntryWC> *auxNode = HM.getBeginning(i);
    while (auxNode != nullptr) {
      push(*auxNode->getData());
      auxNode = auxNode->getNext();
    }
  }
}

template <class T> void OcurrencyQueue<T>::printN(unsigned int n) {
  if (n == 0 || n >= Size) {
    for (unsigned int i = 0; i < Size; i++) {
      T HashEntry = pull();
      cout << HashEntry.getKey() << " " << HashEntry.getCounter() << "\n";
    }
  } else {
    for (unsigned int i = 0; i < n; i++) {
      T HashEntry = pull();
      cout << HashEntry.getKey() << " " << HashEntry.getCounter() << "\n";
    }
  }
}

template <class T> bool OcurrencyQueue<T>::isEmpty() { return last == nullptr; }

#endif // OCURRENCYQUEUE_H