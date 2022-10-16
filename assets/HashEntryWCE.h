#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_

#include <iostream>

using namespace std;

class HashEntry {
private:
  string Key;
  unsigned int Counter;

public:
  HashEntry(string Key) {
    this->Key = Key;
    this->Counter = 1;
  }
  string getKey() { return Key; }
  void setKey(string Key) { this->Key = Key; }
  unsigned int getCounter() { return Counter; }
  void setCounter(unsigned int Counter) { this->Counter = Counter; }
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_