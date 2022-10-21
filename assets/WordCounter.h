#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include "../testAssets/HashMapBT.h"
#include "DictionaryTree.h"
#include "HashMapWC.h"
#include "OcurrencyQueue.h"
#include "OcurrencyArray.h"
#include <algorithm>
#include <fstream>

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
  void show(string Filename, string Word);
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

void WordCounter::show(string Filename, string Word){
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
  HM.remove("de");
  cout << toUpper(Word) << " | " << HM.getCounter(Word) << "\n";
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
  cout.sync_with_stdio(false);
  HMBT.print();
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