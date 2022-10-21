#ifndef OCURRENCYARRAY_H
#define OCURRENCYARRAY_H

#include "HashMapWC.h"

class OcurrencyArray {
private:

public:
  unsigned int Size;
  HashEntryWC **Array;
  OcurrencyArray(unsigned int Size);
  void loadArray(HashMapWC &HM);
  void quickSort(HashEntryWC **arr, int inicio, int fin);
  void shellSort(HashEntryWC **arr);
  void printN(unsigned int n = 0);
};

OcurrencyArray::OcurrencyArray(unsigned int Size) {
  this->Size = Size;
  this->Array = new HashEntryWC *[Size];
}

void OcurrencyArray::loadArray(HashMapWC &HM) {
  unsigned int j = 0;
  for (unsigned int i = 0; i < HM.getSize(); i++) {
    NodeWC<HashEntryWC> *auxNode = HM.getBeginning(i);
    while (auxNode != nullptr) {
      Array[j] = auxNode->getData();
      auxNode = auxNode->getNext();
      j++;
    }
    if (j == Size)
      break;
  }
  // quickSort(Array, 0, Size - 1);
  shellSort(Array);
}

void OcurrencyArray::quickSort(HashEntryWC **arr, int inicio, int fin) {
  int i, j, medio, pivot;
  HashEntryWC *aux;

  medio = (inicio + fin) / 2;
  pivot = arr[medio]->getCounter();
  i = inicio;
  j = fin;

  do {
    while (arr[i]->getCounter() > pivot)
      i++;
    while (arr[j]->getCounter() < pivot)
      j--;

    if (i <= j) {
      aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > inicio)
    quickSort(arr, inicio, j);
  if (i < fin)
    quickSort(arr, i, fin);
}

void OcurrencyArray::shellSort(HashEntryWC **arr){
    HashEntryWC *temp;
    for (int gap = Size / 2; gap > 0; gap /= 2)
    {
        for (unsigned int i = gap; i < Size; i += 1)
        {
            temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap]->getCounter() < temp->getCounter(); j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void OcurrencyArray::printN(unsigned int n) {
  if (n == 0 || n >= Size) {
    for (unsigned int i = 0; i < Size; i++) {
      cout << Array[i]->getKey() << " | " << Array[i]->getCounter() << "\n";
    }
  } else {
    for (unsigned int i = 0; i < n; i++) {
      cout << Array[i]->getKey() << " | " << Array[i]->getCounter() << "\n";
    }
  }
}

#endif // OCURRENCYARRAY_H