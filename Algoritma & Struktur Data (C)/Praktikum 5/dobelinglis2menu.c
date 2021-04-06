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

void SisipUrut()
{
    DNode *cek = head;

    if (NodePertama())
        return;

    else if (head->data > baru->data)
        SisipAwal();

    else
    {
        while (cek != NULL && cek->data < baru->data)
            cek = cek->next;

        if (cek == NULL)
            SisipAkhir();

        else if (cek->data == baru->data)
            printf("\nData yang ingin disisipkan sudah ada\n");

        else
            SisipSebelum(cek->data);
    }
}

void Hapus(int x)
{
    DNode *cek = head;

    if (head == tail)
        head = tail = NULL;

    else
    {
        if (head->data == x)
            HapusAwal();

        if (tail->data == x)
            HapusAkhir();

        else
        {
            while (cek != NULL && cek->data != x)
            {
                cek = cek->next;

                if (cek == NULL)
                {
                    printf("\nData yang ingin dihapus tidak ada\n");
                    return;
                }
            }

            if (cek->data == x)
                HapusTengah(x);
        }
    }

    if (Kosong())
        printf("\nLinked list sudah kosong\n");
}

int main()
{
    int pilih, dt;
    char lagi = 'y';

    printf("1. Sisip urut\n");
    printf("2. Hapus\n\n");

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
            SisipUrut();
            break;

        case 2:
            if (Kosong())
            {
                printf("\nLinked list masih kosong\n");
                break;
            }
            printf("\nMasukkan data: ");
            scanf("%d", &dt);
            Hapus(dt);
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