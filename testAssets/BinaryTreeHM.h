#ifndef BINARYTREEHM_H
#define BINARYTREEHM_H

#include "TreeNodeHE.h"

template <class T> class BinaryTreeHM {
private:
  TreeNodeHE<T> *root;
  T *searchWord(string Word, TreeNodeHE<T> *r);
  void put(T dato, TreeNodeHE<T> *r);
  void preorder(TreeNodeHE<T> *r);
  void inorder(TreeNodeHE<T> *r);
  void postorder(TreeNodeHE<T> *r);
  int diffCounter;

public:
  BinaryTreeHM();
  ~BinaryTreeHM();
  void put(T dato);
  T *searchWord(string Word);
  unsigned int getDiffCounter();
  void preorder();
  void inorder();
  void postorder();
  bool isEmpty();
  void print();
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T> BinaryTreeHM<T>::BinaryTreeHM() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T> BinaryTreeHM<T>::~BinaryTreeHM() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T> T *BinaryTreeHM<T>::searchWord(string Word, TreeNodeHE<T> *r) {
  if (isEmpty())
    return nullptr;
  if (r == nullptr)
    return nullptr;
  if (Word.compare(r->getData()->getKey()) == 0)
    return r->getData();
  if (Word.compare(r->getData()->getKey()) < 0)
    return searchWord(Word, r->getLeft());
  else
    return searchWord(Word, r->getRight());
}

template <class T> T *BinaryTreeHM<T>::searchWord(string Word) {
  return searchWord(Word, root);
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T> void BinaryTreeHM<T>::put(T dato, TreeNodeHE<T> *r) {
  TreeNodeHE<T> *newTreeNode = new TreeNodeHE<T>(dato);
  if (isEmpty()) {
    root = newTreeNode;
    diffCounter++;
    return;
  }

  if (dato.getKey() == r->getData()->getKey()) {
    // Aumenta en 1 las ocurrencias
    r->getData()->setCounter(r->getData()->getCounter() + 1);
    return;
  }
  if (dato.getKey() < r->getData()->getKey()) {
    if (r->getLeft() == nullptr) {
      r->setLeft(newTreeNode);
      diffCounter++;
      return;
    }
    put(dato.getKey(), r->getLeft());
  } else {
    if (r->getRight() == nullptr) {
      r->setRight(newTreeNode);
      diffCounter++;
      return;
    }
    put(dato.getKey(), r->getRight());
  }
}

template <class T> void BinaryTreeHM<T>::put(T dato) { put(dato, root); }

/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T> bool BinaryTreeHM<T>::isEmpty() { return root == nullptr; }

template <class T> void BinaryTreeHM<T>::preorder() { preorder(root); }
template <class T> void BinaryTreeHM<T>::preorder(TreeNodeHE<T> *r) {
  if (r == nullptr)
    return;
  cout << r->getData()->getKey() << " ";
  preorder(r->getLeft());
  preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template <class T> void BinaryTreeHM<T>::inorder() { inorder(root); }
template <class T> void BinaryTreeHM<T>::inorder(TreeNodeHE<T> *r) {
  if (r == nullptr)
    return;
  inorder(r->getLeft());
  cout << r->getData()->getKey() << " ";
  inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template <class T> void BinaryTreeHM<T>::postorder() { postorder(root); }
template <class T> void BinaryTreeHM<T>::postorder(TreeNodeHE<T> *r) {
  if (r == nullptr)
    return;
  postorder(r->getLeft());
  postorder(r->getRight());
  cout << r->getData()->getKey() << " ";
}

template <class T> unsigned int BinaryTreeHM<T>::getDiffCounter() {
  return diffCounter;
}

/**
 * Muestra un árbol por consola
 */
template <class T> void BinaryTreeHM<T>::print() {
  if (root != nullptr)
    root->print(false, "");
  else
    cout << endl << "VACIO";
}

#endif // BINARYTREEHM_H
