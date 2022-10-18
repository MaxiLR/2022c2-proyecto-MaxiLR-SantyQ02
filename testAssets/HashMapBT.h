#ifndef HASHMAPBT_H
#define HASHMAPBT_H

#include "BinaryTreeHM.h"
#include "HashEntryWCE.h"
#include <math.h>
#include <string>

class HashMapBT {
private:
  BinaryTreeHM<HashEntry> **Table;
  unsigned int Size;
  unsigned int hashFunc(string Key);
  string toUpper(string Str);

public:
  HashMapBT();
  ~HashMapBT();
  unsigned int getDiffCounter();
  unsigned int getCounter(string Key);
  string getKey(string Key);
  void put(string Key);
  void remove(string Key);
  bool isEmpty();
  void print();
};

HashMapBT::HashMapBT() {
  this->Size = 677;
  Table = new BinaryTreeHM<HashEntry> *[Size];
  for (int i = 0; i < Size; i++) {
    Table[i] = new BinaryTreeHM<HashEntry>;
  }
}

HashMapBT::~HashMapBT() {
  for (int i = 0; i < Size; i++) {
    if (Table[i] != nullptr) {
      delete Table[i];
    }
  }
}

unsigned int HashMapBT::getDiffCounter() {
  unsigned int diffWordCount = 0;
  for (int i = 0; i < Size; i++) {
    if (!Table[i]->isEmpty()) {
      diffWordCount += Table[i]->getDiffCounter();
    }
  }
  return diffWordCount;
}

unsigned int HashMapBT::getCounter(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntry *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getCounter();
}

string HashMapBT::getKey(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntry *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getKey();
}

void HashMapBT::put(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntry newHE(toUpper(Key));
  Table[pos]->put(newHE);
}

void HashMapBT::remove(string Key) {}

bool HashMapBT::isEmpty() {
  for (int i = 0; i < Size; i++) {
    if (Table[i] != nullptr)
      return false;
  }
  return true;
}

string HashMapBT::toUpper(string Str) {
  for (int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

unsigned int HashMapBT::hashFunc(string Key) {
  if (toupper(Key[0]) < 65 || toupper(Key[0]) > 90)
    return 26;
  return toupper(Key[0]) - 65;
}

void HashMapBT::print() {
  for (int i = 0; i < Size; i++) {
    if (!Table[i]->isEmpty()) {
      Table[i]->inorder();
      cout << endl << endl;
    }
  }
}

#endif // HASHMAPBT_H
