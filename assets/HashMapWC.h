#ifndef HASHMAPWC_H
#define HASHMAPWC_H

#include "HashEntryWC.h"
#include "ListWC.h"
#include <math.h>

class HashMapWC {
private:
  ListWC<HashEntryWC> **Table;
  unsigned int HECounter;
  unsigned int Size;
  unsigned int hashFunc(string Key);
  string toUpper(string Str);

public:
  explicit HashMapWC(unsigned int Size);
  ~HashMapWC();
  NodeWC<HashEntryWC>* getBeginning(unsigned int i);
  unsigned int getEmptyCells();
  unsigned int getHECount();
  unsigned int getCounter(string Key);
  unsigned int getSize();
  string getKey(string Key);
  void put(string Key);
  void remove(string Key);
  bool isEmpty();
};

HashMapWC::HashMapWC(unsigned int Size) {
  this->Size = Size;
  this->HECounter = 0;
  Table = new ListWC<HashEntryWC> *[Size];
  for (unsigned int i = 0; i < Size; i++) {
    Table[i] = new ListWC<HashEntryWC>;
  }
}

HashMapWC::~HashMapWC() {
  for (unsigned int i = 0; i < Size; i++) {
    if (Table[i] != nullptr) {
      delete Table[i];
    }
  }
}

NodeWC<HashEntryWC> *HashMapWC::getBeginning(unsigned int i){
  return Table[i]->getBeginning();
}

unsigned int HashMapWC::getHECount() { return HECounter; }

unsigned int HashMapWC::getCounter(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntryWC *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getCounter();
}

string HashMapWC::getKey(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntryWC *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getKey();
}

unsigned int HashMapWC::getSize() { return Size; }

void HashMapWC::put(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntryWC *TablePos = Table[pos]->searchWord(Key);

  if (TablePos != nullptr) {
    TablePos->setCounter(TablePos->getCounter() + 1);
    return;
  }

  HashEntryWC newHE(toUpper(Key));
  Table[pos]->autoinsert(newHE);
  HECounter++;
}

void HashMapWC::remove(string Key) {}

bool HashMapWC::isEmpty() {
  for (unsigned int i = 0; i < Size; i++) {
    if (Table[i] != nullptr)
      return false;
  }
  return true;
}

unsigned int HashMapWC::hashFunc(string Key) {
  unsigned int hash;
  for (unsigned int i = 0; i < Key.length(); i++) {
    hash = 31 * hash + toupper(Key[i]);
  }
  return hash;
}

string HashMapWC::toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

#endif // U05_HASH_HASHMAP_HASHMAP_H_