#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

template <class T> class TreeNode {
private:
  T Word;
  unsigned int WordCount;
  TreeNode *left, *right;

public:
  TreeNode() {
    this->WordCount = 1;
    left = nullptr;
    right = nullptr;
  }
  TreeNode(T Word) {
    this->Word = Word;
    this->WordCount = 1;
    left = nullptr;
    right = nullptr;
  }
  T getData() const { return Word; }
  void setDato(T d) { Word = d; }
  unsigned int getWordCount() { return WordCount; }
  void setWordCount(unsigned int WordCount) { this->WordCount = WordCount; }
  TreeNode *getRight() const { return right; }
  void setRight(TreeNode *r) { right = r; }
  TreeNode *getLeft() const { return left; }
  void setLeft(TreeNode *l) { left = l; }
  void print(bool esDerecho, string identacion) {
    if (right != nullptr) {
      right->print(true, identacion + (esDerecho ? "     " : "|    "));
    }
    cout << identacion;
    if (esDerecho) {
      cout << " /";
    } else {
      cout << " \\";
    }
    cout << "-- ";
    cout << Word << endl;
    if (left != nullptr) {
      left->print(false, identacion + (esDerecho ? "|    " : "     "));
    }
  }
};

#endif // TREENODE_H
