#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int data[MAX];

void GuessingGame(int n)
{
    int i = 0, L = 0, R = n - 1, m, temp = n;
    char pil;

    while (L <= R)
    {
        m = (L + R) / 2;

        fflush(stdin);
        printf("Apakah angka yang Anda pikirkan lebih kecil dari %d? (y/t) ", m);
        scanf("%c", &pil);

        if (pil == 'y')
        {
            temp = m;
            R = m - 1;
        }
        else
            L = m + 1;
    }

    if (pil == 't')
        printf("\nKarena angkanya lebih kecil dari %d tapi tidak lebih kecil dari %d, maka angkanya pasti %d", temp, m, m);
    else
    {
        if (m - 1 == (n - 1) / 2)
            printf("\nAngkanya berada di tengah, jadi Anda pasti memikirkan antara angka %d atau %d", m, m - 1);
        else
            printf("\nTidak mungkin angka yang Anda pikirkan lebih kecil daripada %d!", m);
    }
}

void main()
{
    int i, n, key;
    char pil;

    printf("\nMasukkan batasan (n): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        data[i] = i + 1;

    printf("\nPikirkan suatu angka mulai dari 1 sampai dengan %d\n", n);
    printf("Sekarang bimbing program untuk menemukan angka tersebut!\n\n");

    GuessingGame(n);
}