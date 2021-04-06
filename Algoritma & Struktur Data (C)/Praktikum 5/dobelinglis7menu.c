#include <stdio.h>
#include <stdlib.h>

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

void Cetak()
{
    DNode *p = head;

    if (Kosong())
        return;

    printf("\nCetak head - tail:\n");

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

void CetakTail()
{
    if (Kosong())
        return;

    DNode *p = tail;

    printf("\nCetak tail - head:\n");

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }

    printf("\n");
}

void SisipAwal()
{
    if (NodePertama())
        return;

    baru->next = head;
    head->prev = baru;
    head = baru;
}

void SisipAkhir()
{
    if (NodePertama())
        return;

    baru->prev = tail;
    tail->next = baru;
    tail = baru;
}

void SisipSebelum(int x)
{
    if (NodePertama())
        return;

    DNode *before = head;

    while (before->data != x)
        before = before->next;

    baru->prev = before->prev;
    baru->next = before;
    before->prev->next = baru;
    before->prev = baru;
}

void SisipSetelah(int x)
{
    if (NodePertama())
        return;

    DNode *after = head;

    while (after->data != x)
        after = after->next;

    baru->prev = after;
    baru->next = after->next;
    after->next->prev = baru;
    after->next = baru;
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

void HapusAkhir()
{
    DNode *hapus = tail;
    tail->prev->next = NULL;
    tail = hapus->prev;
    FreeDNode(hapus);
}

void HapusTengah(int x)
{
    DNode *hapus = head;
    while (hapus->data != x)
        hapus = hapus->next;
    hapus->prev->next = hapus->next;
    hapus->next->prev = hapus->prev;
    FreeDNode(hapus);
}

int main()
{
    int pilih, dt;
    char lagi = 'y';

    printf("1. Sisip awal\n");
    printf("2. Sisip akhir\n");
    printf("3. Sisip sebelum\n");
    printf("4. Sisip sesudah\n");
    printf("5. Hapus awal\n");
    printf("6. Hapus akhir\n");
    printf("7. Hapus tengah\n\n");

    while (lagi == 'y' || lagi == 'Y')
    {
        printf("\nPilihan: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            printf("\nMasukkan data: ");
            scanf("%d", &dt);
            AlokasiSimpul(dt);
            SisipAwal();
            break;
        case 2:
            printf("\nMasukkan data: ");
            scanf("%d", &dt);
            AlokasiSimpul(dt);
            SisipAkhir();
            break;
        case 3:
            printf("\nMasukkan data: ");
            scanf("%d", &dt);
            AlokasiSimpul(dt);
            printf("\nSisipkan sebelum: ");
            scanf("%d", &dt);
            SisipSebelum(dt);
            break;
        case 4:
            printf("\nMasukkan data: ");
            scanf("%d", &dt);
            AlokasiSimpul(dt);
            printf("\nSisipkan setelah: ");
            scanf("%d", &dt);
            SisipSetelah(dt);
            break;
        case 5:
            HapusAwal();
            break;
        case 6:
            HapusAkhir();
            break;
        case 7:
            printf("\nMasukkan data: ");
            scanf("%d", &dt);
            HapusTengah(dt);
            break;

        default:
            printf("\nPilihan Anda salah\n");
        }

        Cetak();
        CetakTail();

        fflush(stdin);
        printf("\nIngin mengulang? (Y / T) >> ");
        scanf("%c", &lagi);
    }

    return 0;
}