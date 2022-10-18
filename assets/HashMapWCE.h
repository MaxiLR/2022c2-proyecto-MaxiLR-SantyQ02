#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntryWCE.h"
#include "ListWCE.h"
#include <math.h>
#include <string>

class HashMap {
private:
  List<HashEntry> **Table;
  unsigned int HECounter;
  unsigned int Size;
  unsigned int NotEmptyCellCounter; // Debugging
  unsigned int hashFunc(string Key);
  string toUpper(string Str);

public:
  HashMap();
  unsigned int getEmptyCells();
  unsigned int getCollitionCounter(); // Debugging
  unsigned int getHECounter();
  unsigned int getCounter(string Key);
  string getKey(string Key);
  void put(string Key);
  void remove(string Key);
  ~HashMap();
  bool esVacio();
};

HashMap::HashMap() {
  this->Size = 252525;
  this->HECounter = 0;
  this->NotEmptyCellCounter = 0; // Debugging
  Table = new List<HashEntry> *[Size];
  for (int i = 0; i < Size; i++) {
    Table[i] = new List<HashEntry>;
  }
}

HashMap::~HashMap() {
  for (int i = 0; i < Size; i++) {
    if (Table[i] != nullptr) {
      delete Table[i];
    }
  }
}

unsigned int HashMap::getEmptyCells() {
  unsigned int y = 0;
  for (int i = 0; i < Size; i++) {
    if (Table[i]->isEmpty()) {
      y++;
    }
  }
  return y;
}

unsigned int HashMap::getCollitionCounter() {
  for (int i = 0; i < Size; i++) {
    if (!Table[i]->isEmpty()) {
      NotEmptyCellCounter++;
    }
  }
  return HECounter - NotEmptyCellCounter;
}

unsigned int HashMap::getHECounter() { return HECounter; }

unsigned int HashMap::getCounter(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntry *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getCounter();
}

string HashMap::getKey(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntry *TablePos = Table[pos]->searchWord(Key);

  if (TablePos == nullptr)
    throw 404;

  return TablePos->getKey();
}

void HashMap::put(string Key) {
  unsigned int pos = hashFunc(Key) % Size;
  HashEntry newHE(toUpper(Key));
  Table[pos]->autoinsert(newHE);
  HECounter++;
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

unsigned int HashMap::hashFunc(string Key) {
  string hash;
  for (int i = 0; i < 3; i++) {
    hash += to_string(toupper(Key[i]));
  }
  return stoi(hash) - 656565;
}

#endif // U05_HASH_HASHMAP_HASHMAP_H_
