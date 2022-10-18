#ifndef BINARYTREEWC_H
#define BINARYTREEWC_H

#include "TreeNodeWC.h"

class BinaryTreeWC {
private:
  TreeNodeWC<string> *root;
  unsigned int search(string Word, TreeNodeWC<string> *r); 
  void put(string Word, TreeNodeWC<string> *r);
  void preorder(TreeNodeWC<string> *r);
  void inorder(TreeNodeWC<string> *r);
  void postorder(TreeNodeWC<string> *r);
  int diffCounter;

public:
  BinaryTreeWC();
  void put(string Word);
  unsigned int search(string Word);
  void preorder();
  void inorder();
  void postorder();
  ~BinaryTreeWC();
  bool isEmpty();
  void print();
  unsigned int getDiffCounter();
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam string Valor guardado por el árbol
 */
BinaryTreeWC::BinaryTreeWC() {
  root = nullptr;
  diffCounter = 0;
}

/**
 * Destructor del Arbol
 */
BinaryTreeWC::~BinaryTreeWC() {}

/**
 * Busca un Word en el árbol. Si no esta el Word en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
unsigned int BinaryTreeWC::search(string Word) { return search(Word, root); }

unsigned int BinaryTreeWC::search(string Word, TreeNodeWC<string> *r) {
  if (isEmpty())
    return 0;
  if (r == nullptr)
    return 0;
  if (Word.compare(r->getData()) == 0)
    return r->getWordCount();
  if (Word.compare(r->getData()) < 0)
    return search(Word, r->getLeft());
  else
    return search(Word, r->getRight());
}

/**
 * Agrega un Word al árbol
 * @param clave Clave para agregar el Word
 * @param Word Dato a agregar
 */
void BinaryTreeWC::put(string Word) { put(Word, root); }

void BinaryTreeWC::put(string Word, TreeNodeWC<string> *r) {
  TreeNodeWC<string> *newTreeNode = new TreeNodeWC<string>(Word);
  if (isEmpty()) {
    root = newTreeNode;
    diffCounter++;
    return;
  }

  if (Word.compare(r->getData()) == 0) {
    r->setWordCount(
        r->getWordCount() +
        1); // Aumentar ocurrencias, agregar atributo a clase TreeNodeWC
    return;
  }
  if (Word.compare(r->getData()) < 0) {
    if (r->getLeft() == nullptr) {
      r->setLeft(newTreeNode);
      diffCounter++;
      return;
    }
    put(Word, r->getLeft());
  } else {
    if (r->getRight() == nullptr) {
      r->setRight(newTreeNode);
      diffCounter++;
      return;
    }
    put(Word, r->getRight());
  }
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
bool BinaryTreeWC::isEmpty() { return root == nullptr; }

void BinaryTreeWC::preorder() { preorder(root); }
void BinaryTreeWC::preorder(TreeNodeWC<string> *r) {
  if (r == nullptr)
    return;
  cout << r->getData() << " ";
  preorder(r->getLeft());
  preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
void BinaryTreeWC::inorder() { inorder(root); }
void BinaryTreeWC::inorder(TreeNodeWC<string> *r) {
  if (r == nullptr)
    return;
  inorder(r->getLeft());
  cout << r->getData() << " ";
  inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
void BinaryTreeWC::postorder() { postorder(root); }
void BinaryTreeWC::postorder(TreeNodeWC<string> *r) {
  if (r == nullptr)
    return;
  postorder(r->getLeft());
  postorder(r->getRight());
  cout << r->getData() << " ";
}

unsigned int BinaryTreeWC::getDiffCounter() { return diffCounter; }

/**
 * Muestra un árbol por consola
 */
void BinaryTreeWC::print() {
  if (root != nullptr)
    root->print(false, "");
  else
    cout << endl << "VACIO";
}

#endif // BINARYTREE_H
