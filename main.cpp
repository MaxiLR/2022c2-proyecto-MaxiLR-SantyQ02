#include "assets/WordCounter.h"
#include <ctime>
#include <iostream>

#define TEXT_1 "testTexts/txt.txt"
#define TEXT_2 "testTexts/Words.txt"
#define TEXT_3 "testTexts/mucho_texto.txt"

using namespace std;

//-palabras [n]: Mostrará las n primeras palabras en orden alfabético. Si n no
//es ingresado o vale 0, mostrará todas las palabras
// [DictionaryTree]
//-ocurrencias [n]: Mostrará las n palabras y la cantidad de ocurrencias de c/u
//ordenadas de mayor a menor por ocurrencia. Si n no es ingresado o vale 0,
//mostrará todas las palabras
// [HashMapWC + OcurrenciesQueue]
//-mostrar [palabra],[palabra] : Mostrará la o las palabras pasadas como
//argumento ordenadas por ocurrencia.
//[HashMapWC + OcurrenciesQueue]
//-excluir [palabra],[palabra] : Modifica los comandos ocurrencias y palabras
//haciendo que no muestren las palabras pasadas como argumentos.
// [Delete according to structure]
//-excluirf [archivo.txt] : Modifica los comandos ocurrencias y palabras
//haciendo que no muestren las palabras que contiene el archivo.txt.
// [Delete according to structure]

string toUpper(string Str) {
  for (unsigned int i = 0; i < Str.length(); i++) {
    Str[i] = toupper(Str[i]);
  }
  return Str;
}

int main() {

  WordCounter WC;

  clock_t begin = clock();

  WC.words("testTexts/txt.txt");

  clock_t end = clock();

  // cout << "WORDS: " << WC.getWordCount()
  //      << " | LETTERS: " << WC.getLetterCount()
  //      << " | LINES: " << WC.getLineCount()
  //      << " | DIFFWORDS: " << WC.getDiffWordCount() << endl;
  double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
  cout << "Tiempo: " << elapsed_secs << "\n";
  return 0;
}
