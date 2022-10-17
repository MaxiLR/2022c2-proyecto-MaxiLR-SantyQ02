#include "assets/HashMapWCE.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

unsigned int hashFunction(string key) {
  unsigned int crypt = 0;
  for (int i = 0; i < key.length(); i++) {
    crypt += tolower(key[i]) * pow(11, key.length() - i);
  }
  return crypt;
}

// unsigned int hashFunctionTest(){
//   int arr[377461], i = 0, collitions = 0;
//   string word;
//   ifstream file("Words.txt");
//   while (!file.eof() && i < 377461) {
//     file >> word;
//     arr[i] = hashFunction(word);
//     for (int j = 0; j < i; j++) {
//       if (arr[j] == arr[i]) {
//         collitions++;
//         break;
//       }
//     }
//     i++;
//   }
//   file.close();
//   return collitions;
// }

int main() {

  clock_t begin;
  begin = clock();

  HashMap HMTest(65535, hashFunction);

  try {
    string word;
    ifstream file("mucho_texto.txt");
    while (!file.eof()) {
      file >> word;
      HMTest.put(word);
    }
    file.close();
    cout << HMTest.getCounter("la") << endl
         << "Cantidad de Palabras Distintas: " << HMTest.getHECounter() << endl
         << "Cantidad de Colisiones: " << HMTest.getCollitionCounter() << endl;
    cout << "Cantidad de Celdas Vacias: " << HMTest.getEmptyCells();
  } catch (int err) {
    cerr << "Error " << err << "!" << endl;
  }

  clock_t end = clock();

  double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

  cout << endl << "Tiempo: " << elapsed_secs << "\n" << endl;

  return 0;
}
