#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int data[MAX];

void GuessingGame(int n)
{
    int i = 0, L = 0, R = n - 1, m, temp1 = n, temp2;
    char pil;

    while (L <= R)
    {
        m = (L + R) / 2;

        fflush(stdin);
        printf("Apakah angka yang Anda pikirkan lebih kecil dari %d? (y/t) ", m);
        scanf("%c", &pil);

        if (pil == 'y')
        {
            temp1 = m;
            R = m - 1;
        }
        else
        {
            temp2 = m;
            L = m + 1;
        }
    }

    if (pil == 't')
        printf("\nKarena angkanya lebih kecil dari %d tapi tidak lebih kecil dari %d, maka angkanya pasti %d\n\n", temp1, m, m);
    else
    {
        if (m - 1 == (n - 1) / 2)
            printf("\nAngkanya berada di tengah, jadi Anda pasti memikirkan antara angka %d atau %d\n\n", m, m - 1);
        else if (temp1 > temp2)
            printf("\nKarena angkanya lebih kecil dari %d tapi tidak lebih kecil dari %d, maka angkanya pasti %d\n\n", temp1, temp2, temp2);
        else
            printf("\nTidak mungkin angka yang Anda pikirkan lebih kecil daripada %d!\n\n", m);
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
