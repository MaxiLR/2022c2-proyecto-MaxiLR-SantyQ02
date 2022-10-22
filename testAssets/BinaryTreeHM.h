#ifndef BINARYTREEHM_H
#define BINARYTREEHM_H

#include "TreeNodeHE.h"

template <class T> class BinaryTreeHM {
private:
  TreeNodeHE<T> *root;
  T *searchWord(string Word, TreeNodeHE<T> *r);
  TreeNodeHE<T> *searchNode(string Word, TreeNodeHE<T> *r);
  void putTree(TreeNodeHE<T> *root);
  void put(T data, TreeNodeHE<T> *r);
  void preorder(TreeNodeHE<T> *r);
  void inorder(TreeNodeHE<T> *r);
  void inorderN(TreeNodeHE<T> *r, unsigned int n, unsigned int &count);
  void postorder(TreeNodeHE<T> *r);
  string toUpper(string Str);
  int diffCounter;

public:
  BinaryTreeHM();
  ~BinaryTreeHM();
  void put(T data);
  T *searchWord(string Word);
  TreeNodeHE<T> *searchNode(string Word);
  void remove(string Word);
  unsigned int getDiffCounter();
  void preorder();
  void inorderN(int n);
  void postorder();
  bool isEmpty();
  void print();
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T> BinaryTreeHM<T>::BinaryTreeHM() {
  root = nullptr;
  diffCounter = 0;
}

/**
 * Destructor del Arbol
 */
template <class T> BinaryTreeHM<T>::~BinaryTreeHM() {}

/**
 * Busca un data en el árbol. Si no esta el data en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T>
T *BinaryTreeHM<T>::searchWord(string Word, TreeNodeHE<T> *r) {
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
 * Agrega un data al árbol
 * @param clave Clave para agregar el data
 * @param data data a agregar
 */
template <class T> void BinaryTreeHM<T>::put(T data, TreeNodeHE<T> *r) {
  TreeNodeHE<T> *newTreeNode = new TreeNodeHE<T>(data);
  if (isEmpty()) {
    root = newTreeNode;
    diffCounter++;
    return;
  }

  if (data.getKey() == r->getData()->getKey()) {
    // Aumenta en 1 las ocurrencias
    r->getData()->setCounter(r->getData()->getCounter() + 1);
    return;
  }
  if (data.getKey() < r->getData()->getKey()) {
    if (r->getLeft() == nullptr) {
      r->setLeft(newTreeNode);
      diffCounter++;
      return;
    }
    put(data.getKey(), r->getLeft());
  } else {
    if (r->getRight() == nullptr) {
      r->setRight(newTreeNode);
      diffCounter++;
      return;
    }
    put(data.getKey(), r->getRight());
  }
}

template <class T> void BinaryTreeHM<T>::put(T data) { put(data, root); }

template <class T>
TreeNodeHE<T> *BinaryTreeHM<T>::searchNode(string Word, TreeNodeHE<T> *r) {
  if (isEmpty())
    throw 404;
  if (Word == root->getData()->getKey())
    return r;
  if (Word > r->getData()->getKey()) {
    if (r->getRight() == nullptr)
      throw 409;
    if (Word == r->getRight()->getData()->getKey()) {
      return r;
    }
    return searchNode(Word, r->getRight());
  } else {
    if (r->getLeft() == nullptr)
      throw 407;
    if (Word == r->getLeft()->getData()->getKey()) {
      return r;
    }
    return searchNode(Word, r->getLeft());
  }
}

template <class T> TreeNodeHE<T> *BinaryTreeHM<T>::searchNode(string Word) {
  return searchNode(Word, root);
}

template <class T> void BinaryTreeHM<T>::putTree(TreeNodeHE<T> *r) {
  TreeNodeHE<T> *toDelete = r;

  put(*r->getData());
  if (r->getLeft() != nullptr && r->getRight() != nullptr) {
    putTree(r->getLeft());
    putTree(r->getRight());
    delete toDelete;
    return;
  }
  if (r->getLeft() != nullptr && r->getRight() == nullptr) {
    putTree(r->getLeft());
    delete toDelete;
    return;
  }
  if (r->getLeft() == nullptr && r->getRight() != nullptr) {
    putTree(r->getRight());
    delete toDelete;
    return;
  }
  if (r->getLeft() == nullptr && r->getRight() == nullptr) {
    delete toDelete;
    return;
  }
}

/**
 * Elimina un data del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T> void BinaryTreeHM<T>::remove(string Word) {
  TreeNodeHE<T> *toDelete, *auxNodo = searchNode(toUpper(Word));

  if (Word == root->getData()->getKey())
    toDelete = auxNodo;
  else if (Word < auxNodo->getData()->getKey())
    toDelete = auxNodo->getLeft();
  else
    toDelete = auxNodo->getRight();

  if (toDelete->getLeft() == nullptr && toDelete->getRight() == nullptr) {
    if (Word == root->getData()->getKey()) {
      root = nullptr;
      delete toDelete;
      return;
    }
    if (Word < auxNodo->getData()->getKey())
      auxNodo->setLeft(nullptr);
    else
      auxNodo->setRight(nullptr);
    delete toDelete;
    return;
  }
  if (toDelete->getLeft() != nullptr && toDelete->getRight() == nullptr) {
    if (Word == root->getData()->getKey()) {
      root = toDelete->getLeft();
      delete toDelete;
      return;
    }
    if (Word < auxNodo->getData()->getKey())
      auxNodo->setLeft(toDelete->getLeft());
    else
      auxNodo->setRight(toDelete->getLeft());
    delete toDelete;
    return;
  }
  if (toDelete->getLeft() == nullptr && toDelete->getRight() != nullptr) {
    if (Word == root->getData()->getKey()) {
      root = toDelete->getRight();
      delete toDelete;
      return;
    }
    if (Word < auxNodo->getData()->getKey())
      auxNodo->setLeft(toDelete->getRight());
    else
      auxNodo->setRight(toDelete->getRight());
    delete toDelete;
    return;
  }
  if (toDelete->getLeft() != nullptr && toDelete->getRight() != nullptr) {
    if (Word == root->getData()->getKey()) {
      root = toDelete->getLeft();
      putTree(toDelete->getRight());
      delete toDelete;
      return;
    }
    if (Word < auxNodo->getData()->getKey())
      auxNodo->setLeft(toDelete->getLeft());
    else
      auxNodo->setRight(toDelete->getLeft());
    putTree(toDelete->getRight());
    delete toDelete;
    return;
  }
}

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

template <class T> void BinaryTreeHM<T>::inorderN(int n) {
  if (n == 0 || n >= diffCounter) {
    inorder(root);
    return;
  } else if (n < 0)
    return;
  unsigned int i = 0;
  inorderN(root, n, i);
}

template <class T> void BinaryTreeHM<T>::inorder(TreeNodeHE<T> *r) {
  if (r == nullptr)
    return;
  inorder(r->getLeft());
  cout << r->getData()->getKey() << " ";
  inorder(r->getRight());
}

template <class T>
void BinaryTreeHM<T>::inorderN(TreeNodeHE<T> *r, unsigned int n,
                               unsigned int &count) {
  if (r == nullptr)
    return;
  if (count == n)
    return;
  inorderN(r->getLeft(), n, count);
  if (n > count) {
    cout << r->getData()->getKey() << " ";
    count++;
    inorderN(r->getRight(), n, count);
  }
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

template <class T> string BinaryTreeHM<T>::toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
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
