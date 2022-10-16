#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntryWCE.h"

class HashMap {
private:
  HashEntry **table;
  unsigned int HECounter;
  unsigned int size;
  unsigned int (*hashFuncP)(string key);
  string toUpper(string str);

public:
  unsigned int CollitionCounter;
  HashMap(unsigned int size, unsigned int (*hashFuncP)(string));
  unsigned int getHECounter();
  unsigned int getCounter(string key);
  string getKey(string key);
  void put(string key);
  void remove(string key);
  ~HashMap();
  bool esVacio();
};

HashMap::HashMap(unsigned int size, unsigned int (*fp)(string)) {
  this->size = size;
  this->HECounter = 0;
  this->CollitionCounter = 0;
  table = new HashEntry *[size];
  for (int i = 0; i < size; i++) {
    table[i] = nullptr;
  }
  hashFuncP = fp;
}

HashMap::~HashMap() {
  for (int i = 0; i < size; i++) {
    if (table[i] != nullptr) {
      delete table[i];
    }
  }
}

unsigned int HashMap::getHECounter() { return HECounter; }

unsigned int HashMap::getCounter(string key) {
  unsigned int pos = hashFuncP(key) % size;

  if (table[pos] == nullptr)
    throw 404;

  if (table[pos]->getKey() == toUpper(key)) {
    return table[pos]->getCounter();
  }

  throw 409;
}

string HashMap::getKey(string key){
  unsigned int pos = hashFuncP(key) % size;

  if (table[pos] == nullptr)
    throw 404;

  if (table[pos]->getKey() == toUpper(key)) {
    return table[pos]->getKey();
  }

  throw 409;
}

void HashMap::put(string key) {

  unsigned int pos = hashFuncP(key) % size;

  if (table[pos] != nullptr && table[pos]->getKey() == toUpper(key)) {
    table[pos]->setCounter(table[pos]->getCounter() + 1);
    return;
  }
  if (table[pos] != nullptr && table[pos]->getKey() != toUpper(key)) {
    CollitionCounter++;
    return;
  }

  table[pos] = new HashEntry(toUpper(key));
  HECounter++;
}

void HashMap::remove(string key) {}

bool HashMap::esVacio() {
  for (int i = 0; i < size; i++) {
    if (table[i] != nullptr)
      return false;
  }
  return true;
}

string HashMap::toUpper(string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = toupper(str[i]);
  }
  return str;
}

#endif // U05_HASH_HASHMAP_HASHMAP_H_
