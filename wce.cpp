#include "assets/WordCounter.h"
#include <ctime>
#include <iostream>
#include <string.h>

#define TEXT_1 "testTexts/txt.txt"
#define TEXT_2 "testTexts/Words.txt"
#define TEXT_3 "C:/Users/maxim/Downloads/mucho_texto2.txt"
#define TEXT_4 "testTexts/spanish.txt"
#define TEXT_5 "testTexts/modelo.txt"

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

string justAlpha(string str){
    for (unsigned int i = 0; i < str.length(); i++) {
        if (ispunct(str[i])) {
            str.erase(str.begin() + i);
            i = -1;
        }
    }
    return str;
}

int main(int argc, char *argv[]) {
    WordCounter WC;

    clock_t begin = clock();
    std::ios::sync_with_stdio(false);

    switch (argc)
    {
    case 1:
      cout << "Debe ingresar una archivo" << "\n";
      break;

    case 2:
      WC.defaultUse(argv[1]);
      break;

    case 3:
      if(argv[1] == "-palabras"){
        WC.wordsDT(argv[2]);
      }
      else if(argv[1] == "-ocurrencias"){
        WC.ocurrenciesA(argv[2]);
      }
      break;

    case 4:
      if(argv[1] == "-palabras"){
        int n = stoi(justAlpha(argv[2]));
        WC.wordsDT(argv[3], n);
      }
      else if(argv[1] == "-ocurrencias"){
        int n = stoi(justAlpha(argv[2]));
        WC.ocurrenciesA(argv[3], n);
      }
      break;

    case 5:
      if(argv[1] == "-palabras" && argv[2] == "-excluirf"){
        //WC.wordsDT(WC.excludef(argv[4], argv[3]));
      }
      else if(argv[1] == "-ocurrencias" && argv[2] == "-excluirf"){
        //WC.ocurrenciesA(WC.excludef(argv[4], argv[3]));
      }
      break;

    case 6:
      if(argv[1] == "-palabras" && argv[3] == "-excluirf"){
        //WC.wordsDT(WC.excludef(argv[4], argv[3]));
      }
      else if(argv[1] == "-ocurrencias" && argv[3] == "-excluirf"){
        //WC.ocurrenciesA(WC.excludef(argv[5], argv[4]));
      }
      break;
    
    default:
      break;
    }

    if (argv[1] == "-mostrar"){
      int cont = argc-1, size = argc-3;
      string phrase;
      for (size_t i = 3; i < cont; i++){
        phrase = phrase + justAlpha(argv[i] + ' ');
      }
      WC.show(argv[cont], phrase, size);
    }
    else if (argc >4){
      if (argv[1] == "-palabras"){
        if (argv[2] == "-excluir"){
          int cont = argc-1, size = argc-3;
          string phrase;
          for (size_t i = 3; i < cont; i++){
            phrase = phrase + justAlpha(argv[i] + ' ');
          }
          //WC.wordsDT(WC.exclude(argv[cont], phrase));
        }
        else if (argv[1] == "-palabras" && argv[3] == "-excluir"){
          int cont = argc-1, size = argc-4, n = 0;
          string phrase;
          for (size_t i = 4; i < cont; i++){
            phrase = phrase + justAlpha(argv[i] + ' ');
          }
          n = stoi(justAlpha(argv[2]));
          //WC.wordsDT(WC.exclude(argv[cont], phrase), n);
        }
      }
      else if (argv[1] == "-ocurrencias"){
        if (argv[2] == "-excluir"){
          int cont = argc-1, size = argc-3;
          string phrase;
          for (size_t i = 3; i < cont; i++){
            phrase = phrase + justAlpha(argv[i] + ' ');
          }
          //WC.ocurrencies(WC.exclude(argv[cont], phrase));
        }
        else if (argv[3] == "-excluir"){
          int cont = argc-1, size = argc-4, n = 0;
          string phrase;
          for (size_t i = 4; i < cont; i++){
            phrase = phrase + justAlpha(argv[i] + ' ');
          }
          n = stoi(justAlpha(argv[2]));
          //WC.ocurrencies(WC.exclude(argv[cont], phrase));
        }
      }
    }

    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    cout << endl << "Tiempo: " << elapsed_secs << "\n";

    return 0;
}
