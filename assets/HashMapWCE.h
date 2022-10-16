#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntryWCE.h"
#include "ListWCE.h"

class HashMap {
private:
  List<HashEntry> **Table;
  unsigned int HECounter;
  unsigned int Size;
  unsigned int (*hashFuncP)(string Key);
  string toUpper(string Str);

public:
  unsigned int CollitionCounter; // Debugging
  HashMap(unsigned int Size, unsigned int (*hashFuncP)(string));
  unsigned int getHECounter();
  unsigned int getCounter(string Key);
  string getKey(string Key);
  void put(string Key);
  void remove(string Key);
  ~HashMap();
  bool esVacio();
};

HashMap::HashMap(unsigned int Size, unsigned int (*fp)(string)) {
  this->Size = Size;
  this->HECounter = 0;
  this->CollitionCounter = 0; // Debugging
  Table = new List<HashEntry> *[Size];
  for (int i = 0; i < Size; i++) {
    Table[i] = nullptr;
  }
  hashFuncP = fp;
}

HashMap::~HashMap() {
  for (int i = 0; i < Size; i++) {
    if (Table[i] != nullptr) {
      delete Table[i];
    }
  }
}

unsigned int HashMap::getHECounter() { return HECounter; }

unsigned int HashMap::getCounter(string Key) {
  unsigned int pos = hashFuncP(Key) % Size;
  HashEntry *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getCounter();
}

string HashMap::getKey(string Key) {
  unsigned int pos = hashFuncP(Key) % Size;
  HashEntry *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getKey();
}

void HashMap::put(string Key) {

  unsigned int pos = hashFuncP(Key) % Size;
  HashEntry *TablePos = Table[pos]->searchWord(Key);

  if (TablePos != nullptr) {
    TablePos->setCounter(TablePos->getCounter() + 1);
    return;
  }

  HashEntry newHE(Key);
  Table[pos]->insertLast(newHE);
}

void HashMap::remove(string Key) {}

bool HashMap::esVacio() {
  for (int i = 0; i < Size; i++) {
    if (Table[i] != nullptr)
      return false;
  }
  return true;
}

string HashMap::toUpper(string Str) {
  for (int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

#endif // U05_HASH_HASHMAP_HASHMAP_H_
