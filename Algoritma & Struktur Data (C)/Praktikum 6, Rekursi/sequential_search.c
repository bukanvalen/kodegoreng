#include <stdio.h>

void SequentialSearch(int data[], int ukuran, int n)
{
    static int i = 0;

    if (i == ukuran)
    {
        printf("\nData tidak ditemukan!");
        return;
    }

    else if (data[i] == n)
    {
        printf("\nData %d berada pada index ke-%d", n, i);
        return;
    }

    else
    {
        i++;
        SequentialSearch(data, ukuran, n);
    }
}

int main()
{
    int i, n, data[5] = {1, 2, 3, 4, 5}, ukuran = sizeof(data) / sizeof(data[0]);

    printf("Data:");
    for (i = 0; i < ukuran; i++)
    {
        printf(" %d", data[i]);
    }

    printf("\nData yang ingin dicari: ");
    scanf("%d", &n);

    SequentialSearch(data, ukuran, n);
}