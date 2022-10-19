#ifndef OCURRENCYQUEUE_H
#define OCURRENCYQUEUE_H

#include "NodeWC.h"

template <class T> class OcurrencyQueue {
private:
  NodeWC<T> *first, *last;

public:
  OcurrencyQueue();
  ~OcurrencyQueue();
  void push(T data);
  void ocurrencyPush(T data, int ocurrency);
  T pull();
  bool isEmpty();
};

template <class T> OcurrencyQueue<T>::OcurrencyQueue() {
  first = nullptr;
  last = nullptr;
}

template <class T> OcurrencyQueue<T>::~OcurrencyQueue() {
  while (!isEmpty()) {
    pull();
  }

  delete first;
  delete last;
}

template <class T> void OcurrencyQueue<T>::push(T data) {
  NodeWC<T> *new = new NodeWC<T>(data);

  if (isEmpty())
    first = new;
  else
    last->setNext(new);

  last = new;
}

template <class T> T OcurrencyQueue<T>::pull() {
  if (isEmpty())
    throw 400;

  T data = first->getDato();
  NodeWC<T> *toDelete = first;
  first = first->getNext();

  if (first == nullptr)
    last = nullptr;

  delete toDelete;
  return data;
}

template <class T> bool OcurrencyQueue<T>::isEmpty() { return last == nullptr; }

template <class T>
void OcurrencyQueue<T>::ocurrencyPush(T data) {
  if (ocurrency >= WO_PRIORITY) {
    push(data);
    return;
  }

  NodeWC<T> *new = new NodeWC<T>(data, ocurrency);

  if (isEmpty()) {
    new->setNext(nullptr);
    first = new;
    last = new;
    return;
  }
  if (first->getPrioridad() > ocurrency) {
    new->setNext(first);
    first = new;
    return;
  }
  if (first->getNext() == nullptr) {

    first->setNext(new);
    last = new;
    return;
  }
  NodeWC<T> *aux = first;
  while (aux->getNext() != nullptr &&
         aux->getNext()->getPrioridad() <= ocurrency) {
    aux = aux->getNext();
  }

  new->setNext(aux->getNext());
  aux->setNext(new);
}
#endif // OCURRENCYQUEUE_H