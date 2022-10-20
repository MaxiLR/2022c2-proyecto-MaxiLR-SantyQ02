#ifndef TREENODEHE_H
#define TREENODEHE_H

#include <iostream>

using namespace std;

template <class T> class TreeNodeHE {
private:
  T* data;
  unsigned int WordCount;
  TreeNodeHE *left, *right;

public:
  TreeNodeHE() {
    this->WordCount = 1;
    left = nullptr;
    right = nullptr;
  }
  TreeNodeHE(T data) {
    this->data = new T(data);
    this->WordCount = 1;
    left = nullptr;
    right = nullptr;
  }
  T* getData() const { return data; }
  void setData(T d) { *this->data = d; }
  unsigned int getWordCount() { return WordCount; }
  void setWordCount(unsigned int WordCount) { this->WordCount = WordCount; }
  TreeNodeHE *getRight() const { return right; }
  void setRight(TreeNodeHE *r) { right = r; }
  TreeNodeHE *getLeft() const { return left; }
  void setLeft(TreeNodeHE *l) { left = l; }
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
    cout << this->data->getKey() << endl;
    if (left != nullptr) {
      left->print(false, identacion + (esDerecho ? "|    " : "     "));
    }
  }
};

#endif // TREENODEWC_H
