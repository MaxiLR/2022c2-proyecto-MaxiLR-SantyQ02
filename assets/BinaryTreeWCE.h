#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

class BinaryTree {
private:
  TreeNode<string> *root;
  unsigned int search(string Word, TreeNode<string> *r);
  void put(string Word, TreeNode<string> *r);
  void preorder(TreeNode<string> *r);
  void inorder(TreeNode<string> *r);
  void postorder(TreeNode<string> *r);
  int diffCounter;

public:
  BinaryTree();
  void put(string Word);
  unsigned int search(string Word);
  void preorder();
  void inorder();
  void postorder();
  ~BinaryTree();
  bool isEmpty();
  void print();
  unsigned int getDiffCounter();
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam string Valor guardado por el árbol
 */
BinaryTree::BinaryTree() {
  root = nullptr;
  diffCounter = 0;
}

/**
 * Destructor del Arbol
 */
BinaryTree::~BinaryTree() {}

/**
 * Busca un Word en el árbol. Si no esta el Word en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
unsigned int BinaryTree::search(string Word) { return search(Word, root); }

unsigned int BinaryTree::search(string Word, TreeNode<string> *r) {
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
void BinaryTree::put(string Word) { put(Word, root); }

void BinaryTree::put(string Word, TreeNode<string> *r) {
  TreeNode<string> *newTreeNode = new TreeNode<string>(Word);
  if (isEmpty()) {
    root = newTreeNode;
    diffCounter++;
    return;
  }

  if (Word.compare(r->getData()) == 0) {
    r->setWordCount(
        r->getWordCount() +
        1); // Aumentar ocurrencias, agregar atributo a clase TreeNode
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
bool BinaryTree::isEmpty() { return root == nullptr; }

void BinaryTree::preorder() { preorder(root); }
void BinaryTree::preorder(TreeNode<string> *r) {
  if (r == nullptr)
    return;
  cout << r->getData() << " ";
  preorder(r->getLeft());
  preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
void BinaryTree::inorder() { inorder(root); }
void BinaryTree::inorder(TreeNode<string> *r) {
  if (r == nullptr)
    return;
  inorder(r->getLeft());
  cout << r->getData() << " ";
  inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
void BinaryTree::postorder() { postorder(root); }
void BinaryTree::postorder(TreeNode<string> *r) {
  if (r == nullptr)
    return;
  postorder(r->getLeft());
  postorder(r->getRight());
  cout << r->getData() << " ";
}

unsigned int BinaryTree::getDiffCounter() { return diffCounter; }

/**
 * Muestra un árbol por consola
 */
void BinaryTree::print() {
  if (root != nullptr)
    root->print(false, "");
  else
    cout << endl << "VACIO";
}

#endif // BINARYTREE_H
