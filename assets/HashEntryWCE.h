#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_

#include <iostream>

using namespace std;

class HashEntry {
private:
  string key;
  unsigned int counter;

public:
  HashEntry(string key) {
    this->key = key;
    this->counter = 1;
  }
  string getKey() { return key; }
  void setKey(string key) { this->key = key; }
  unsigned int getCounter() { return counter; }
  void setCounter(unsigned int counter) { this->counter = counter; }
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_