#include "assets/HashMapWCE.h"
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

unsigned int hashFunction(string key) {
  unsigned int crypt = 0;
  for (int i = 0; i < key.length(); i++) {
    crypt += tolower(key[i])*pow(11, key.length()-i);
  }
  return crypt;
}

unsigned int hashFunctionTest(){
  int arr[377461], i = 0, collitions = 0;
  string word;
  ifstream file("Words.txt");
  while (!file.eof() && i < 377461) {
    file >> word;
    arr[i] = hashFunction(word);
    for (int j = 0; j < i; j++) {
      if (arr[j] == arr[i]) {
        collitions++;
        break;
      }
    }
    i++;
  }
  file.close();
  return collitions;
}

int main() {
  HashMap HMTest(478293, hashFunction);
  
  string word;
  ifstream file("txt.txt");
  while(!file.eof()){
    file >> word;
    HMTest.put(word);
  }

  cout << HMTest.CollitionCounter;

//   try {
//     cout << "Colisiones: " << hashFunctionTest();
//   } catch (int err) {
//     cerr << "Error " << err << "!" << endl;
//   }

  return 0;
}
