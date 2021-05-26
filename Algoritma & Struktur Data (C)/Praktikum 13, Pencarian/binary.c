#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

int data[MAX];

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int L, int R)
{
    int i, j, key;
    key = data[(L + R) / 2];
    i = L;
    j = R;

    while (i <= j)
    {
        while (data[i] < key)
            i++;
        while (data[j] > key)
            j--;
        if (i <= j)
        {
            Swap(&data[i], &data[j]);
            i++;
            j--;
        }
    }

    if (L < j)
        QuickSort(L, j);
    if (i < R)
        QuickSort(i, R);
}

int BinarySearch(int key, int n)
{
    int L = 0, R = n - 1, m;
    bool ketemu = false;

    while ((L <= R) && (!ketemu))
    {
        m = (L + R) / 2;

        if (data[m] == key)
            ketemu = true;
        else if (key < data[m])
            R = m - 1;
        else
            L = m + 1;
    }

    if (ketemu)
        return m;
    else
        return -1;
}

void main()
{
    int i, n, key;
    srand(0);

    printf("\nMasukkan jumlah data: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        data[i] = rand() / 1000 + 1;

    QuickSort(0, n - 1);

    printf("\nData saat ini: \n");
    for (i = 0; i < n; i++)
        printf("%d ", data[i]);

    printf("\n\nMasukkan data yang ingin dicari (key): ");
    scanf("%d", &key);

    int ketemu = BinarySearch(key, n);
    if (ketemu > 0)
        printf("Data ditemukan pada indeks ke-%d", ketemu);
    else
        printf("Data tidak ditemukan!");
}