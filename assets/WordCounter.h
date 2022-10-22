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
  void show(string Filename, string Word, int Size);
  void wordsDT(string Filename, unsigned int n = 0);
  void wordsHMBT(string Filename, unsigned int n = 0);
  void ocurrenciesQ(string Filename, unsigned int n = 0);
  void ocurrenciesA(string Filename, unsigned int n = 0);
  void excludeWords(string Filename, string *arrStr, unsigned int arrStrSize,
                    unsigned int n);
  void excludefWords(string Filename, unsigned int n, string eFilename);
  void excludeOcurrencies(string Filename, string *arrStr,
                          unsigned int arrStrSize, unsigned int n);
  void excludefOcurrencies(string Filename, unsigned int n, string eFilename);
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

void WordCounter::show(string Filename, string Words, int Size) {
  try {
    ifstream File(Filename);
    HashMapWC HM(499979);
    string word;
    int cont = 0, temp;

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

    string wordArr[Size];
    int ocArr[Size];
    istringstream FileW(Words);
    while (!File.eof()) {
      FileW >> word;
      for (unsigned int i = 0; i < word.length(); i++) {
        if (ispunct(word[i])) {
          word.erase(word.begin() + i);
          i = -1;
        }
      }
      wordArr[cont] = word;
      ocArr[cont] = HM.getCounter(word);
      cont++;
    }
    // Ordenamiento:
    for (int i = 0; i < Size - 1; i++) {
      for (int j = 0; j < Size - i - 1; j++)
        if (ocArr[j] > ocArr[j + 1]) {

          int intAux = ocArr[j];
          ocArr[j] = ocArr[j + 1];
          ocArr[j + 1] = intAux;

          string strAux = wordArr[j];
          wordArr[j] = wordArr[j + 1];
          wordArr[j + 1] = strAux;
        }
    }
    for (int i = 0; i < Size - 1; i++) {
      cout << wordArr[i] << " | " << ocArr[i] << "\n";
    }
  } catch (int err) {
  }
}

void WordCounter::wordsDT(string Filename, unsigned int n) {
  ifstream File(Filename);
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
    HMBT.remove(arrStr[i]);
  }

  HMBT.print(n);
}

void WordCounter::excludefWords(string Filename, unsigned int n,
                                string eFilename) {
  ifstream File(Filename), eFile(eFilename);
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
    HMBT.remove(word);
  }
  eFile.close();

  HMBT.print(n);
}

void WordCounter::excludeOcurrencies(string Filename, string *arrStr,
                                     unsigned int arrStrSize, unsigned int n) {
  ifstream File(Filename);
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
    HM.remove(arrStr[i]);
  }

  OcurrencyArray OA(HM.getHECount());
  OA.loadArray(HM);

  OA.printN(n);
}

void WordCounter::excludefOcurrencies(string Filename, unsigned int n,
                                      string eFilename) {
  ifstream File(Filename), eFile(eFilename);
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
    HM.remove(word);
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