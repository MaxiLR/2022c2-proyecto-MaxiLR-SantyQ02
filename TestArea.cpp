#include "assets/WordCounter.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

// long double hashFunc(string Word) {
//   long double hash = 0;
//   for (int i = 0; i < Word.length(); i++) {
//     cout << int(Word[i]) << endl;
//     hash += int(Word[i]) * pow(100, 23 - i);
//   }
//   return hash;
// }

// int main() { cout << hashFunc("HOLAAAAA") << " | " << hashFunc("HOLB"); }

string toUpper(string Str) {
    for (int i = 0; i < Str.length(); i++) {
        Str[i] = toupper(Str[i]);
    }
    return Str;
}

int main() {

  // clock_t begin = clock();

  // string word;
  // HashMap Hm;
  // ifstream file(TEXT_3);

  // while (!file.eof()) {
  //   file >> word;
  //   Hm.put(word);
  // }

  // clock_t end = clock();
  // double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

  // cout << "Cantidad de colisiones: " << Hm.getCollitionCounter() << endl;
  // cout << "Palabras diferentes: " << Hm.getHECounter() << endl;
  // cout << "Tiempo: " << elapsed_secs;

  // ifstream file("txt.txt");
  // string word;
  // while (file >> word) {
  //   for (auto c : word)
  //     if (ispunct(c) && c != '`')
  //       word.erase(word.find_first_of(c));
  //   cout << word << endl;
  // }

  string word;

  clock_t begin;
  begin = clock();

  TreeHashMap TH;

  try {
    ifstream file(TEXT_3);
    while (!file.eof()) {
      file >> word;
      TH.put(word);
    }
    file.close();
  } catch (int err) {
    cerr << "Error " << err << "!" << endl;
  }
  clock_t end = clock();
  double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

  cout << "Tiempo del Tree Hash: " << elapsed_secs << "\n" << endl;
  cout << "Palabras Diferentes: " << TH.getCounter("HOLA") << endl;

  // Arbol Dictionario:

  clock_t begin3;
  begin3 = clock();

  DictionaryTree DT;

  ifstream file3(TEXT_3);
  while (!file3.eof()) {
    file3 >> word;
    DT.put(word);
  }
  file3.close();

  clock_t end3 = clock();
  double elapsed_secs3 = static_cast<double>(end3 - begin3) / CLOCKS_PER_SEC;
  cout << "Tiempo del Arbol Diccionario: " << elapsed_secs3 << "\n" << endl;

  cout << "Palabras diferentes: " << DT.() << endl;

  // Arbol:

     clock_t begin2;
     begin2 = clock();

     BinaryTree BT;

     ifstream file2(TEXT_3);
     while (!file2.eof()) {
       try {
         file2 >> word;
         BT.put(toUpper(word));
       } catch (int err) {
       }
     }
     file2.close();


     clock_t end2 = clock();
     double elapsed_secs2 = static_cast<double>(end2 - begin2) / CLOCKS_PER_SEC;
     cout << "Tiempo del Arbol Binario: " << elapsed_secs2 << "\n" << endl;

    cout << "Palabras diferentes: " << BT.getDiffCounter() << endl;

  return 0;
}



