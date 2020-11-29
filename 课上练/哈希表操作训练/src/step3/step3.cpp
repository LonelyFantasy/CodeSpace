#include "../hash.h"

int main()
{
  struct hashTable *h = initHashTable_linear();
  //printf("%d\n",h->maxNum);
  printHashTable(h);
}