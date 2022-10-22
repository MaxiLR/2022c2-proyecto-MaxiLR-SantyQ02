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
  ifstream file(Filename);
  HashMapWC HM(499979);
  string word;
  while (!file.eof()) {
    file >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    LetterCount += word.length();
    WordCount++;
    HM.put(word);
    if (file.peek() == '\n' || file.eof())
      LineCount++;
    DiffWordCount = HM.getHECount();
  }
  file.close();
  cout.sync_with_stdio(false);
  cout << "WORDS: " << WordCount << " | LETTERS: " << LetterCount
       << " | LINES: " << LineCount << " | DIFFWORDS: " << DiffWordCount;
}

void WordCounter::show(string Filename, string Words, int Size) {
  try {
    string word;
    int cont = 0, temp;

    ifstream file(Filename);
    HashMapWC HM(499979);
    while (!file.eof()) {
      file >> word;
      for (unsigned int i = 0; i < word.length(); i++) {
        if (ispunct(word[i])) {
          word.erase(word.begin() + i);
          i = -1;
        }
      }
      HM.put(word);
    }
    file.close();


    string wordArr[Size];
    int ocArr[Size];
    istringstream fileW(Words);
    while (!file.eof()) {
      fileW >> word;
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
    //Ordenamiento:
    for (int i = 0; i < Size-1; i++){
      for (int j = 0; j < Size - i - 1; j++)
            if (ocArr[j] > ocArr[j + 1]){

              int intAux = ocArr[j];
              ocArr[j] = ocArr[j+1];
              ocArr[j+1] = intAux;

              string strAux = wordArr[j];
              wordArr[j] = wordArr[j+1];
              wordArr[j+1] = strAux;

            }
    }
    for (int i = 0; i < Size-1; i++){
      cout << wordArr[i] << " | "  << ocArr[i] << "\n";
    }
  } catch (int err) {
  }
}

void WordCounter::wordsDT(string Filename, unsigned int n) {
  ifstream file(Filename);
  DictionaryTree DT;
  string word;
  while (!file.eof()) {
    file >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    DT.put(word);
  }
  file.close();
  cout.sync_with_stdio(false);
  DT.inorder(n);
}

void WordCounter::wordsHMBT(string Filename, unsigned int n) {
  ifstream file(Filename);
  HashMapBT HMBT;
  string word;
  while (!file.eof()) {
    file >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HMBT.put(word);
  }
  file.close();
  // HMBT.remove("de");
  cout.sync_with_stdio(false);
  HMBT.print(n);
}

void WordCounter::ocurrenciesA(string Filename, unsigned int n) {
  ifstream file(Filename);

  HashMapWC HM(499979);
  string word;

  while (!file.eof()) {
    file >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HM.put(word);
  }
  file.close();

  OcurrencyArray OA(HM.getHECount());
  OA.loadArray(HM);

  cout.sync_with_stdio(false);

  OA.printN(n);
}

void WordCounter::ocurrenciesQ(string Filename, unsigned int n) {
  ifstream file(Filename);

  OcurrencyQueue<HashEntryWC> OQ;
  HashMapWC HM(499979);
  string word;

  while (!file.eof()) {
    file >> word;
    for (unsigned int i = 0; i < word.length(); i++) {
      if (ispunct(word[i])) {
        word.erase(word.begin() + i);
        i = -1;
      }
    }
    HM.put(word);
  }
  file.close();

  cout.sync_with_stdio(false);

  OQ.loadQueue(HM);
  OQ.printN(n);
}

string WordCounter::toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

#endif // WORDCOUNTER_H