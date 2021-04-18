#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;

struct simpul
{
    char data;
    Node *next;
};

Node *top = NULL, *baru;

int Empty()
{
    if (top == NULL)
        return 1;

    else
        return 0;
}

void AlokasiSimpul(int x)
{
    baru = (Node *)malloc(sizeof(Node));

    if (baru == NULL)
    {
        printf("Alokasi Memori Gagal");
        exit(1);
    }

    else
    {
        baru->data = x;
        baru->next = NULL;
    }
}

void Cetak()
{
    Node *p = top;

    if (Empty())
        printf("\nStack masih kosong!\n");

    else
    {
        printf("\nSimpul-simpul yang ada saat ini:\n");
        while (p != NULL)
        {
            printf("%c ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void Push(int x)
{
    AlokasiSimpul(x);

    if (Empty())
        top = baru;

    else
    {
        baru->next = top;
        top = baru;
    }
}

void FreeNode(Node *p)
{
    free(p);
    p = NULL;
}

char Pop()
{
    Node *hapus = top;
    char cetak;

    cetak = hapus->data;
    top = hapus->next;
    FreeNode(hapus);

    return cetak;
}

void cetakKonversi(int n, char tipe[])
{
    int i, hitung, temp;

    for (i = 0; n > 0; i++)
    {
        hitung = i + 1;

        if (tipe == "Biner")
        {
            temp = n % 2;
            Push(temp);
            n = n / 2;
        }

        if (tipe == "Oktal")
        {
            temp = n % 8;
            Push(temp);
            n = n / 8;
        }

        if (tipe == "Heksadesimal")
        {
            temp = n % 16;
            Push(temp);
            n = n / 16;
        }
    }

    printf("\n%s: ", tipe);
    for (i = 0; i < hitung; i++)
    {
        if (tipe == "Heksadesimal")
        {
            temp = Pop();

            if (temp <= 9)
                printf("%d", temp);
            else
                printf("%c", temp + 55);
        }

        else
            printf("%d", Pop());
    }
}

int main()
{
    int input;
    char lagi = 'y';

    while (lagi == 'y' || lagi == 'Y')
    {
        printf("\nMasukkan angka desimal, nanti akan dikonversikan ke biner, oktal, dan heksadesimal: ");

        scanf("%d", &input);
        fflush(stdin);

        cetakKonversi(input, "Biner");
        cetakKonversi(input, "Oktal");
        cetakKonversi(input, "Heksadesimal");

        printf("\n\nIngin mengulang? (Y / T) >> ");
        scanf("%c", &lagi);
    }
    return 0;
}