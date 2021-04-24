#include <stdio.h>

int pascal(int row, int col)
{
    if (row == col || col == 0)
        return 1;
    else
        return pascal(row - 1, col) + pascal(row - 1, col - 1);
}

int main()
{
    int i, j, n;
    printf("Masukkan batas segitiga Pascal: ");
    scanf("%d", &n);

    for (i = 0; n > i; i++)
    {
        printf("F%d\t", i + 1);

        for (j = 0; j < n - i; j++)
            printf(" ");

        for (j = 0; i >= j; j++)
            printf("%d ", pascal(i, j));

        printf("\n");
    }
    return 0;
}