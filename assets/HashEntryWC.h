#ifndef HASHENTRYWC_H
#define HASHENTRYWC_H

#include <iostream>

using namespace std;

class HashEntryWC {
private:
  string Key;
  unsigned int Counter;

public:
  HashEntryWC(string Key) {
    this->Key = Key;
    this->Counter = 1;
  }
  string getKey() { return Key; }
  void setKey(string Key) { this->Key = Key; }
  unsigned int getCounter() { return Counter; }
  void setCounter(unsigned int Counter) { this->Counter = Counter; }
};

#endif // HASHENTRYWC_H