#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include "DictionaryTree.h"
#include "HashMapWC.h"
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
  void words(string Filename, unsigned int n = 0);
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

void WordCounter::words(string Filename, unsigned int n) {
  ifstream file(Filename);
  BinaryTreeWC DT;
  string word;
  while (!file.eof()) {
    file >> word;
    DT.put(word);
  }
  file.close();
  cout.sync_with_stdio(false);
  DT.inorderN(n);
}

string WordCounter::toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

#endif // WORDCOUNTER_H