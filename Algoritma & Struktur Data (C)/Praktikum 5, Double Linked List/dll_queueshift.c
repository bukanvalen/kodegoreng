#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct simpul DNode;

struct simpul
{
    int data;
    DNode *next;
    DNode *prev;
};

DNode *head = NULL, *tail = NULL, *baru;

void AlokasiSimpul(int x)
{
    baru = (DNode *)malloc(sizeof(DNode));

    if (baru == NULL)
    {
        printf("Alokasi Memori Gagal");
        exit(1);
    }

    else
    {
        baru->data = x;
        baru->next = NULL;
        baru->prev = NULL;
    }
}

int Kosong()
{
    return head == NULL && tail == NULL;
}

int NodePertama()
{
    if (Kosong())
    {
        head = tail = baru;
        return 1;
    }

    else
        return 0;
}

void SisipAkhir()
{
    if (NodePertama())
        return;

    baru->prev = tail;
    tail->next = baru;
    tail = baru;
}

void FreeDNode(DNode *p)
{
    free(p);
    p = NULL;
}

void HapusAwal()
{
    DNode *hapus = head;
    head->next->prev = NULL;
    head = hapus->next;
    FreeDNode(hapus);
}

void Enqueue(int x)
{
    DNode *cek = head;

    AlokasiSimpul(x);

    if (NodePertama())
        return;

    else
        SisipAkhir();
}

int Dequeue()
{
    DNode *cek = head;
    int temp = head->data;

    if (head == tail)
        head = tail = NULL;

    else
        HapusAwal();

    return temp;
}

int OpShift(int n, int s)
{
    int tmp = 0, e = 0;

    while (n > 0)
    {
        Enqueue(n % 2);
        n /= 2;
    }

    for (int i = 0; i < s; i++)
        Enqueue(Dequeue());

    while (!Kosong())
    {
        tmp += Dequeue() * pow(2.0, e);
        e++;
    }

    return tmp;
}

int main()
{
    int desimal, shift, temp;
    char lagi = 'y';

    while (lagi == 'y' || lagi == 'Y')
    {
        printf("\nMasukkan bilangan desimal: ");
        scanf("%d", &desimal);
        printf("Shift berapa kali? ");
        scanf("%d", &shift);
        fflush(stdin);
        printf("\nBilangan desimal setelah shift adalah: %d\n", OpShift(desimal, shift));
        printf("\nIngin mengulang? (Y / T) >> ");
        scanf("%c", &lagi);
    }

    return 0;
}