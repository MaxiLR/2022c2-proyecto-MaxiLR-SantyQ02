#include "assets/WordCounter.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <math.h>

#define TEXT_1 "txt.txt"
#define TEXT_2 "Words.txt"
#define TEXT_3 "mucho_texto.txt"

using namespace std;

int main() {

  clock_t begin;
  begin = clock();

  WordCounter WC;

  WC.defaultUse(TEXT_1);

  cout << "WORDS: " << WC.getWordCount() << " | LETTERS: " << WC.getLetterCount() << " | LINES: " << WC.getLineCount() << " | DIFFWORDS: " << WC.getDiffWordCount();

  clock_t end = clock();
  double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
  cout << endl << "Tiempo: " << elapsed_secs << "\n" << endl;

  // string word;

  // // Hash:

  // clock_t begin;
  // begin = clock();

  // HashMap HMTest(500000);

  // try {
  //   ifstream file("mucho_texto.txt");
  //   while (!file.eof()) {
  //     file >> word;
  //     HMTest.put(word);
  //   }
  //   file.close();
  //   cout << HMTest.getCounter("ABRIR") << endl
  //        << "Palabras Diferentes: " << HMTest.getHECounter() << endl;
  // } catch (int err) {
  //   cerr << "Error " << err << "!" << endl;
  // }

  // clock_t end = clock();
  // double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
  // cout << "Tiempo del Hash: " << elapsed_secs << "\n" << endl;

  // // Arbol:

  // clock_t begin2;
  // begin2 = clock();

  // BinaryTree BT;

  // ifstream file2("mucho_texto.txt");
  // while (!file2.eof()) {
  //   try {
  //     file2 >> word;
  //     BT.put(toUpper(word));
  //   } catch (int err) {
  //   }
  // }
  // file2.close();

  // cout << "Palabras diferentes: " << BT.getDiffCounter() << endl;

  // clock_t end2 = clock();
  // double elapsed_secs2 = static_cast<double>(end2 - begin2) / CLOCKS_PER_SEC;
  // cout << "Tiempo del Arbol: " << elapsed_secs2 << "\n" << endl;

  // // Arbol Dictionario:

  // clock_t begin3;
  // begin3 = clock();

  // DictionaryTree DT;

  // ifstream file3("mucho_texto.txt");
  // while (!file3.eof()) {
  //   file3 >> word;
  //   DT.put(word);
  // }
  // file3.close();

  // cout << "Palabras diferentes: " << DT.getDiffCounter() << endl;

  // clock_t end3 = clock();
  // double elapsed_secs3 = static_cast<double>(end3 - begin3) / CLOCKS_PER_SEC;
  // cout << "Tiempo del Arbol: " << elapsed_secs3 << "\n" << endl;

  return 0;
}
