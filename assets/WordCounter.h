#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include "../testAssets/HashMapBT.h"
#include "DictionaryTree.h"
#include "HashMapWC.h"
#include "OcurrencyArray.h"
#include "OcurrencyQueue.h"
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class WordCounter {
private:
  unsigned int LetterCount, WordCount, LineCount, DiffWordCount;
  string toUpper(string Str);

public:
  WordCounter();
  unsigned int getLetterCount();
  unsigned int getWordCount();
  unsigned int getLineCount();
  unsigned int getDiffWordCount();
  void defaultUse(string Filename);
  void show(string Filename, string *arrStr, unsigned int arrStrSize);
  void wordsDT(string Filename, unsigned int n = 0);
  void wordsHMBT(string Filename, unsigned int n = 0);
  void ocurrenciesQ(string Filename, unsigned int n = 0);
  void ocurrenciesA(string Filename, unsigned int n = 0);
  void excludeWords(string Filename, string *arrStr, unsigned int arrStrSize,
                    unsigned int n = 0);
  void excludefWords(string Filename, string eFilename, unsigned int n = 0);
  void excludeOcurrencies(string Filename, string *arrStr,
                          unsigned int arrStrSize, unsigned int n = 0);
  void excludefOcurrencies(string Filename, string eFilename,
                           unsigned int n = 0);
};

WordCounter::WordCounter() {
  this->LetterCount = 0;
  this->WordCount = 0;
  this->LineCount = 0;
  this->DiffWordCount = 0;
}

unsigned int WordCounter::getLetterCount() { return LetterCount; }

unsigned int WordCounter::getWordCount() { return WordCount; }

unsigned int WordCounter::getLineCount() { return LineCount; }

unsigned int WordCounter::getDiffWordCount() { return DiffWordCount; }

void WordCounter::defaultUse(string Filename) {
  ifstream File(Filename);
  if (File.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  HashMapWC HM(499979);
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    LetterCount += word.length();
    WordCount++;
    HM.put(word);
    if (File.peek() == '\n' || File.eof())
      LineCount++;
    DiffWordCount = HM.getHECount();
  }
  File.close();

  cout << "WORDS: " << WordCount << " | LETTERS: " << LetterCount
       << " | LINES: " << LineCount << " | DIFFWORDS: " << DiffWordCount;
}

void WordCounter::show(string Filename, string *arrStr,
                       unsigned int arrStrSize) {
  try {
    ifstream File(Filename);
    if (File.fail()) {
      cout << "Error al abrir el archivo!";
      exit(EXIT_FAILURE);
    }

    HashMapWC HM(499979);
    string word;
    int cont = 0, temp = 0, ocAr[arrStrSize];

    while (!File.eof()) {
      File >> word;
      for (unsigned int i = 0; i < word.length(); i++) {
        if (ispunct(word[i])) {
          word.erase(word.begin() + i);
          i = -1;
        }
      }
      HM.put(word);
    }
    File.close();

    for (int i = 0; i < arrStrSize; i++) {
      ocAr[i] = HM.getCounter(arrStr[i]);
    }

    // Ordenamiento:
    for (int i = 0; i < arrStrSize; i++) {
      for (int j = 0; j < arrStrSize - i - 1; j++)
        if (ocAr[j + 1] > ocAr[j]) {

          int intAux = ocAr[j];
          ocAr[j] = ocAr[j + 1];
          ocAr[j + 1] = intAux;

          string strAux = arrStr[j];
          arrStr[j] = arrStr[j + 1];
          arrStr[j + 1] = strAux;
        }
    }
    for (int i = 0; i < arrStrSize; i++) {
      cout << toUpper(arrStr[i]) << " | " << ocAr[i] << "\n";
    }
  } catch (int err) {
  }
}

void WordCounter::wordsDT(string Filename, unsigned int n) {
  ifstream File(Filename);
  if (File.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  DictionaryTree DT;
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    DT.put(word);
  }
  File.close();

  DT.inorder(n);
}

void WordCounter::wordsHMBT(string Filename, unsigned int n) {
  ifstream File(Filename);
  if (File.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  HashMapBT HMBT;
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HMBT.put(word);
  }
  File.close();
  // HMBT.remove("de");

  HMBT.print(n);
}

void WordCounter::ocurrenciesA(string Filename, unsigned int n) {
  ifstream File(Filename);
  if (File.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  HashMapWC HM(499979);
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HM.put(word);
  }
  File.close();

  OcurrencyArray OA(HM.getHECount());
  OA.loadArray(HM);

  OA.printN(n);
}

void WordCounter::ocurrenciesQ(string Filename, unsigned int n) {
  ifstream File(Filename);
  if (File.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  OcurrencyQueue<HashEntryWC> OQ;
  HashMapWC HM(499979);
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HM.put(word);
  }
  File.close();

  OQ.loadQueue(HM);
  OQ.printN(n);
}

void WordCounter::excludeWords(string Filename, string *arrStr,
                               unsigned int arrStrSize, unsigned int n) {
  ifstream File(Filename);
  if (File.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  HashMapBT HMBT;
  string word;
  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HMBT.put(word);
  }
  File.close();

  for (int i = 0; i < arrStrSize; i++) {
    try {
      HMBT.remove(arrStr[i]);
    } catch (int err) {
    }
  }

  HMBT.print(n);
}

void WordCounter::excludefWords(string Filename, string eFilename,
                                unsigned int n) {
  ifstream File(Filename), eFile(eFilename);
  if (File.fail() || eFile.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  HashMapBT HMBT;
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HMBT.put(word);
  }
  File.close();

  while (!eFile.eof()) {
    eFile >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    try {
      HMBT.remove(word);
    } catch (int err) {
    }
  }
  eFile.close();

  HMBT.print(n);
}

void WordCounter::excludeOcurrencies(string Filename, string *arrStr,
                                     unsigned int arrStrSize, unsigned int n) {
  ifstream File(Filename);
  if (File.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  HashMapWC HM(499979);
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HM.put(word);
  }
  File.close();

  for (int i = 0; i < arrStrSize; i++) {
    try {
      HM.remove(arrStr[i]);
    } catch (int err) {
    }
  }

  OcurrencyArray OA(HM.getHECount());
  OA.loadArray(HM);

  OA.printN(n);
}

void WordCounter::excludefOcurrencies(string Filename, string eFilename,
                                      unsigned int n) {
  ifstream File(Filename), eFile(eFilename);
  if (File.fail() || eFile.fail()) {
    cout << "Error al abrir el archivo!";
    exit(EXIT_FAILURE);
  }

  HashMapWC HM(499979);
  string word;

  while (!File.eof()) {
    File >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HM.put(word);
  }
  File.close();

  while (!eFile.eof()) {
    eFile >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    try {
      HM.remove(word);
    } catch (int err) {
    }
  }
  eFile.close();

  OcurrencyArray OA(HM.getHECount());
  OA.loadArray(HM);

  OA.printN(n);
}

string WordCounter::toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

#endif // WORDCOUNTER_H