#include "assets/WordCounter.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

string toUpper(string Str) {
    for (int i = 0; i < Str.length(); i++) {
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

  // for (int i = 0; i < 1000; i++)
  //   cout << teststring;
  // /* Display timing results, code trimmed for brevity */

  // end = clock();
  // double long elapsed_sec = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  // std::ios_base::sync_with_stdio(false);

  // start = clock();
  // for (int i = 0; i < 1000; i++) {
  //   printf(teststring);
  // }
  // end = clock();
  // double long elpased_se = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  // /* Display timing results, code trimmed for brevity */

  // cout << "Tiempo del COUT: " << elapsed_sec << " | Tiempo del PrintF: " << elpased_se;

  char a = 'á';

  a = toupper(a);

  cout << char(161);

  return 0;
}



