#include <iostream>
#include <math.h>

using namespace std;

long double hashFunc(string Word) {
  long double hash = 0;
  for (int i = 0; i < Word.length(); i++) {
    cout << int(Word[i]) << endl;
    hash += int(Word[i]) * pow(100, 23 - i);
  }
  return hash;
}

int main() { cout << hashFunc("HOLAAAAA") << " | " << hashFunc("HOLB"); }
