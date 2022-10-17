#ifndef LIST_H
#define LIST_H

#include "Node.h"

/**
 * Clase que implementa una List Enlazada generica, ya que puede
 * almacenar cualquier tipo de data T
 * @tparam T cualquier tipo de data
 */
template <class T> class List {
private:
  Node<T> *beginning;
  int Size;
  string toUpper(string Str);

public:
  List();
  List(const List<T> &li);
  ~List() { delete beginning; }
  Node<T> *getBeginning();
  void setBeginning(Node<T> *);
  bool isEmpty();
  int getSize();
  void setSize(int);
  void insert(int pos, T data);
  void insertFirst(T data);
  void insertLast(T data);
  void remove(int pos);
  T* getData(int pos);
  T* searchWord(string Key);
  void replace(int pos, T data);
  void empty();
};

/**
 * Constructor de la clase List
 * @tparam T
 */
template <class T> List<T>::List() {
  beginning = nullptr;
  Size = 0;
}
/**
 * Constructor por copia de la clase List
 * @tparam T
 * @param li
 */
template <class T> List<T>::List(const List<T> &li) {}

/**
 * Metodo para obtener puntero beginning de la lista
 * @tparam T
 * @return beginning de la lista
 */
template <class T> Node<T> *List<T>::getBeginning() { return beginning; }

/**
 * Metodo para setear puntero beginning de la lista
 * @tparam T
 * @param beginning
 */

template <class T> void List<T>::setBeginning(Node<T> *beginning) {
  this->beginning = beginning;
}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool List<T>::isEmpty() { return beginning == nullptr; }
/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int List<T>::getSize() { return Size; }

template <class T> void List<T>::setSize(int Size) { this->Size = Size; }

/**
 * Inserta un nodo con el data en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el data
 * @param data  data a insert
 */
template <class T> void List<T>::insert(int pos, T data) {
  int posActual = 0;
  Node<T> *auxNode = beginning, *newNode;
  newNode = new Node<T>(data);

  if (pos == 0) {
    newNode->setNext(beginning);
    beginning = newNode;
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
template <class T> void List<T>::insertFirst(T data) {
  Node<T> *newNode;
  newNode = new Node<T>(data);

  newNode->setNext(beginning);
  beginning = newNode;
  Size++;
}
/**
 * Inserta un nodo con el data en la ultima posicion
 * @tparam T
 * @param data data a insert
 */
template <class T> void List<T>::insertLast(T data) {
  Node<T> *auxNode = beginning, *newNode;
  newNode = new Node<T>(data);

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
template <class T> void List<T>::remove(int pos) {
  int posActual1 = 0, posActual2 = 0;
  Node<T> *auxNode1 = beginning, *auxNode2;

  if (isEmpty())
    throw 405;

  if (pos == 0) {
    beginning = beginning->getNext();
    delete auxNode1;
    return;
  }

  // Node anterior al que se desea eliminar
  while (auxNode1 != nullptr && posActual1 < pos - 1) {
    auxNode1 = auxNode1->getNext();
    posActual1++;
  }

  if (auxNode1 == nullptr)
    throw 405;

  // Node que se desea eliminar
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
template <class T> T* List<T>::getData(int pos) {
  Node<T> *auxNode = beginning;
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

template <class T> T *List<T>::searchWord(string Key) {
  Node<T> *auxNode;
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
template <class T> void List<T>::replace(int pos, T data) {
  int posActual = 0;
  Node<T> *auxNode = beginning;

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
template <class T> void List<T>::empty() {
  Node<T> *auxNode = beginning;
  beginning = nullptr;
  delete auxNode;
  Size = 0;
}

template <class T> string List<T>::toUpper(string Str) {
  for (int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

#endif // U02_LISTAS_LISTA_LISTA_H_
