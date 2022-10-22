#include "assets/WordCounter.h"
#include <algorithm>
#include <ctime>
#include <fcntl.h>
#include <io.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define TEXT_1 "testTexts/txt.txt"
#define TEXT_2 "testTexts/Words.txt"
#define TEXT_3 "C:/Users/maxim/Downloads/mucho_texto2.txt"
#define TEXT_4 "testTexts/spanish.txt"
#define TEXT_5 "testTexts/modelo.txt"

using namespace std;

string toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

int main() {

  // const char *teststring = "Test output string\n";
  // clock_t start, end;
  // double duration;

  // cout << "Starting cout test." << endl;
  // start = clock();

  // std::ios_base::sync_with_stdio(false);

  // for (unsigned int i = 0; i < 1000; i++)
  //   cout << teststring;
  // /* Display timing results, code trimmed for brevity */

  // end = clock();
  // double long elapsed_sec = static_cast<double>(end - start) /
  // CLOCKS_PER_SEC;

  // std::ios_base::sync_with_stdio(false);

  // start = clock();
  // for (unsigned int i = 0; i < 1000; i++) {
  //   printf(teststring);
  // }
  // end = clock();
  // double long elpased_se = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  // /* Display timing results, code trimmed for brevity */

  // cout << "Tiempo del COUT: " << elapsed_sec << " | Tiempo del PrintF: " <<
  // elpased_se;

  WordCounter WC;

  try {
    clock_t begin = clock();
    std::ios::sync_with_stdio(false);

    WC.wordsHMBT(TEXT_5, 4);

    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    cout << endl << "Tiempo: " << elapsed_secs << "\n";


  } catch (int err) {
    cout << err;
  }
}
