#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

int data[MAX];

int SequentialSearch(int key, int n)
{
  int i = 0;
  bool ketemu = false;

  while ((!ketemu) && (i < n))
  {
    if (data[i] == key)
      ketemu = true;
    else
      i++;
  }

  if (ketemu)
    return i;
  else
    return -1;
}

void main()
{
  int i, n, key;
  srand(0);

  printf("\nMasukkan jumlah data: ");
  scanf("%d", &n);

  printf("\nData saat ini: \n");
  for (i = 0; i < n; i++)
  {
    data[i] = rand() / 1000 + 1;
    printf("%d ", data[i]);
  }
  
  printf("\n\nMasukkan data yang ingin dicari (key): ");
  scanf("%d", &key);

  int ketemu = SequentialSearch(key, n);
  if (ketemu > 0)
    printf("Data ditemukan pada indeks ke-%d", ketemu);
  else
    printf("Data tidak ditemukan!");
}