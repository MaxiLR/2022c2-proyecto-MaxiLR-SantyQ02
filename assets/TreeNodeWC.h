#ifndef TREENODEWC_H
#define TREENODEWC_H

#include <iostream>

using namespace std;

template <class T> class TreeNodeWC {
private:
  T Word;
  unsigned int WordCount;
  TreeNodeWC *left, *right;

public:
  TreeNodeWC() {
    this->WordCount = 1;
    left = nullptr;
    right = nullptr;
  }
  TreeNodeWC(T Word) {
    this->Word = Word;
    this->WordCount = 1;
    left = nullptr;
    right = nullptr;
  }
  T getData() const { return Word; }
  void setDato(T d) { Word = d; }
  unsigned int getWordCount() { return WordCount; }
  void setWordCount(unsigned int WordCount) { this->WordCount = WordCount; }
  TreeNodeWC *getRight() const { return right; }
  void setRight(TreeNodeWC *r) { right = r; }
  TreeNodeWC *getLeft() const { return left; }
  void setLeft(TreeNodeWC *l) { left = l; }
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
