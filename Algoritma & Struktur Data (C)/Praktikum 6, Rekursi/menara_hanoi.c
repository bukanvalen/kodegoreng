#include <stdio.h>
#include <math.h>

void menara(int n, char pasak1, char pasak2, char pasak3)
{
    if (n > 0)
    {
        menara(n - 1, pasak1, pasak3, pasak2);
        printf("Pindahkan balok ke-%d dari %c ke %c\n", n, pasak1, pasak3);
        menara(n - 1, pasak2, pasak1, pasak3);
    }
}

int main()
{
    int n;
    printf("Masukkan banyak balok n : ");
    scanf("%d", &n);
    menara(n, 'A', 'B', 'C');
}