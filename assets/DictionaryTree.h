#ifndef DICTIONARYTREE_H
#define DICTIONARYTREE_H

#include "BinaryTreeWC.h"

class DictionaryTree {
private:
  BinaryTreeWC *AG, *HN, *OU, *VZ;
  unsigned int diffCounter;
  string toUpper(string Word);

public:
  DictionaryTree();
  void put(string Word);
  unsigned int search(string Word);
  void inorder(unsigned int n);
  unsigned int getDiffCounter();
};

DictionaryTree::DictionaryTree() {
  AG = new BinaryTreeWC;
  HN = new BinaryTreeWC;
  OU = new BinaryTreeWC;
  VZ = new BinaryTreeWC;
  diffCounter = 0;
}

void DictionaryTree::put(string Word) {
  Word = toUpper(Word);
  if (int(Word[0]) < 79) {
    if (int(Word[0]) < 72)
      AG->put(Word);
    else
      HN->put(Word);
  } else {
    if (int(Word[0]) < 86)
      OU->put(Word);
    else
      VZ->put(Word);
  }
}

unsigned int DictionaryTree::search(string Word) {
  Word = toUpper(Word);
  if (int(Word[0]) < 79) {
    if (int(Word[0]) < 72)
      return AG->search(Word);
    else
      return HN->search(Word);
  } else {
    if (int(Word[0]) < 86)
      return OU->search(Word);
    else
      return VZ->search(Word);
  }
}

void DictionaryTree::inorder(unsigned int n) {
  if(n == 0){
    AG->inorderN(n);
    HN->inorderN(n);
    OU->inorderN(n);
    VZ->inorderN(n);
    return;
  }
  AG->inorderN(n);
  HN->inorderN(n - AG->getDiffCounter());
  OU->inorderN(n - AG->getDiffCounter() - OU->getDiffCounter());
  VZ->inorderN(n - AG->getDiffCounter() - HN->getDiffCounter() -
              OU->getDiffCounter());
}

unsigned int DictionaryTree::getDiffCounter() {
  return AG->getDiffCounter() + HN->getDiffCounter() + OU->getDiffCounter() +
         VZ->getDiffCounter();
}

string DictionaryTree::toUpper(string Word) {
  for (unsigned int i = 0; i < Word.length(); i++) {
    Word[i] = toupper(Word[i]);
  }
  return Word;
}

#endif // DICTIONARYTREE_H