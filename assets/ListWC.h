#ifndef LISTWC_H
#define LISTWC_H

#include "NodeWC.h"

/**
 * Clase que implementa una ListWC Enlazada generica, ya que puede
 * almacenar cualquier tipo de data T
 * @tparam T cualquier tipo de data
 */
template <class T> class ListWC {
private:
  NodeWC<T> *beginning;
  int Size;
  string toUpper(string Str);

public:
  ListWC();
  ListWC(const ListWC<T> &li);
  ~ListWC() { delete beginning; }
  NodeWC<T> *getBeginning();
  void setBeginning(NodeWC<T> *);
  bool isEmpty();
  int getSize();
  void setSize(int);
  void insert(int pos, T data);
  void autoinsert(T data);
  void insertFirst(T data);
  void insertLast(T data);
  void remove(int pos);
  T *getData(int pos);
  T *searchWord(string Key);
  void replace(int pos, T data);
  void empty();
};

/**
 * Constructor de la clase ListWC
 * @tparam T
 */
template <class T> ListWC<T>::ListWC() {
  beginning = nullptr;
  Size = 0;
}
/**
 * Constructor por copia de la clase ListWC
 * @tparam T
 * @param li
 */
template <class T> ListWC<T>::ListWC(const ListWC<T> &li) {}

/**
 * Metodo para obtener puntero beginning de la lista
 * @tparam T
 * @return beginning de la lista
 */
template <class T> NodeWC<T> *ListWC<T>::getBeginning() { return beginning; }

/**
 * Metodo para setear puntero beginning de la lista
 * @tparam T
 * @param beginning
 */

template <class T> void ListWC<T>::setBeginning(NodeWC<T> *beginning) {
  this->beginning = beginning;
}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool ListWC<T>::isEmpty() { return beginning == nullptr; }
/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int ListWC<T>::getSize() { return Size; }

template <class T> void ListWC<T>::setSize(int Size) { this->Size = Size; }

template <class T> void ListWC<T>::autoinsert(T data) {
  NodeWC<T> *auxNode = beginning, *newNode = new NodeWC<T>(data);
  newNode->setNext(nullptr);

  if (isEmpty()) {
    beginning = newNode;
    Size++;
    return;
  }

  if (data.getKey().compare(auxNode->getData()->getKey()) < 0) {
    newNode->setNext(beginning);
    beginning = newNode;
    Size++;
    return;
  }

  while (auxNode->getNext() != nullptr &&
         data.getKey().compare(auxNode->getNext()->getData()->getKey()) > 0) {
    auxNode = auxNode->getNext();
  }

  if (auxNode->getNext() == nullptr) {
    auxNode->setNext(newNode);
    Size++;
    return;
  }

  newNode->setNext(auxNode->getNext());
  auxNode->setNext(newNode);
  Size++;
}

/**
 * Inserta un nodo con el data en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el data
 * @param data  data a insert
 */
template <class T> void ListWC<T>::insert(int pos, T data) {
  int posActual = 0;
  NodeWC<T> *auxNode = beginning, *newNode;
  newNode = new NodeWC<T>(data);

  if (pos == 0) {
    newNode->setNext(beginning);
    beginning = newNode;
    Size++;
    return;
  }

  while (auxNode != nullptr && posActual < pos - 1) {
    auxNode = auxNode->getNext();
    posActual++;
  }

  if (auxNode == nullptr) {
    throw 404;
  }

  newNode->setNext(auxNode->getNext());
  auxNode->setNext(newNode);
  Size++;
}
/**
 * Inserta un nodo con el data en la primera posicion
 * @tparam T
 * @param data data a insert
 */
template <class T> void ListWC<T>::insertFirst(T data) {
  NodeWC<T> *newNode;
  newNode = new NodeWC<T>(data);

  newNode->setNext(beginning);
  beginning = newNode;
  Size++;
}
/**
 * Inserta un nodo con el data en la ultima posicion
 * @tparam T
 * @param data data a insert
 */
template <class T> void ListWC<T>::insertLast(T data) {
  NodeWC<T> *auxNode = beginning, *newNode;
  newNode = new NodeWC<T>(data);

  if (isEmpty()) {
    insertFirst(data);
    return;
  }

  while (auxNode->getNext() != nullptr) {
    auxNode = auxNode->getNext();
  }

  auxNode->setNext(newNode);
  newNode->setNext(nullptr);
  Size++;
}
/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void ListWC<T>::remove(int pos) {
  int posActual1 = 0, posActual2 = 0;
  NodeWC<T> *auxNode1 = beginning, *auxNode2;

  if (isEmpty())
    throw 405;

  if (pos == 0) {
    beginning = beginning->getNext();
    delete auxNode1;
    return;
  }

  // NodeWC anterior al que se desea eliminar
  while (auxNode1 != nullptr && posActual1 < pos - 1) {
    auxNode1 = auxNode1->getNext();
    posActual1++;
  }

  if (auxNode1 == nullptr)
    throw 405;

  // NodeWC que se desea eliminar
  auxNode2 = auxNode1->getNext();

  auxNode1->setNext(auxNode2->getNext());
  auxNode2->setNext(nullptr);
  delete auxNode2;
  Size--;
}
/**
 * Obtener el data del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del data
 * @return data almacenado en el nodo
 */
template <class T> T *ListWC<T>::getData(int pos) {
  NodeWC<T> *auxNode = beginning;
  int posActual = 0;

  if (isEmpty())
    throw 405;

  while (auxNode != nullptr && posActual < pos) {
    auxNode = auxNode->getNext();
    posActual++;
  }

  if (auxNode == nullptr)
    throw 406;

  return auxNode->getData();
}

template <class T> T *ListWC<T>::searchWord(string Key) {
  NodeWC<T> *auxNode;
  auxNode = beginning;

  if (isEmpty())
    return nullptr;

  while (auxNode != nullptr && auxNode->getData()->getKey() != toUpper(Key)) {
    auxNode = auxNode->getNext();
  }

  if (auxNode == nullptr)
    return nullptr;

  return auxNode->getData();
}

/**
 * Reemplaza el data almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea replace
 * @param data newNode data a almacenar
 */
template <class T> void ListWC<T>::replace(int pos, T data) {
  int posActual = 0;
  NodeWC<T> *auxNode = beginning;

  if (isEmpty())
    throw 407;

  while (auxNode != nullptr && posActual < pos) {
    auxNode = auxNode->getNext();
    posActual++;
  }

  if (auxNode == nullptr)
    throw 408;

  auxNode->setDato(data);
}
/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void ListWC<T>::empty() {
  NodeWC<T> *auxNode = beginning;
  beginning = nullptr;
  delete auxNode;
  Size = 0;
}

template <class T> string ListWC<T>::toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

#endif // LISTWC_H
