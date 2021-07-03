// Untuk post-test mata kuliah Praktikum Algoritma dan Struktur Data
// Politeknik Elektronika Negeri Surabaya, 1 D3 IT B
#include <stdio.h>
#include <stdlib.h>
typedef struct simpul Node;
struct simpul
{
    int konstanta;
    int pangkat;
    Node *next;
};

Node *head = NULL, *baru;

void AlokasiSimpul(int konstanta, int pangkat)
{
    baru = (Node *)malloc(sizeof(Node));
    if (baru == NULL)
    {
        printf("Alokasi Memori Gagal");
        exit(1);
    }
    else
    {
        baru->konstanta = konstanta;
        baru->pangkat = pangkat;
        baru->next = NULL;
    }
}

void Cetak()
{
    Node *p = head;
    while (p != NULL)
    {
        printf("%d", p->konstanta);
        if (p->pangkat != 1)
            printf("x^%d", p->pangkat);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

void SisipAwal()
{
    baru->next = head;
    head = baru;
}

void SisipAkhir()
{
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = baru;
}

void SisipSebelum(int x)
{
    Node *before = head;
    while (before->next->pangkat != x)
        before = before->next;
    baru->next = before->next;
    before->next = baru;
}

void FreeNode(Node *p)
{
    free(p);
    p = NULL;
}

void HapusAwal()
{
    Node *hapus = head;
    head = hapus->next;
    FreeNode(hapus);
}

void HapusAkhir()
{
    Node *hapus = head, *before;
    while (hapus->next != NULL)
    {
        before = hapus;
        hapus = hapus->next;
    }
    before->next = NULL;
    FreeNode(hapus);
}

void HapusTengah(int x)
{
    Node *hapus = head, *before;
    while (hapus->pangkat != x)
    {
        before = hapus;
        hapus = hapus->next;
    }
    before->next = hapus->next;
    FreeNode(hapus);
}

void SisipUrut()
{
    Node *cek = head;
    if (head == NULL)
        head = baru;
    else if (head->pangkat < baru->pangkat)
        SisipAwal();
    else
    {
        while (cek != NULL && cek->pangkat > baru->pangkat)
            cek = cek->next;
        if (cek == NULL)
            SisipAkhir();
        else if (cek->pangkat == baru->pangkat)
            printf("\nData yang ingin disisipkan sudah ada (pangkat %d)\n", cek->pangkat);
        else
            SisipSebelum(cek->pangkat);
    }
}

void HapusUrut(int x)
{
    Node *cek = head;
    if (head == NULL)
        printf("Linked list masih kosong\n");
    else
    {
        if (head->pangkat == x)
            HapusAwal();
        else
        {
            while (cek != NULL && cek->pangkat != x)
            {
                cek = cek->next;
                if (cek == NULL)
                {
                    printf("Data yang ingin dihapus tidak ada\n");
                    return;
                }
            }
            if (cek->pangkat == x)
                HapusTengah(x);
            else if (cek->pangkat == x && cek->next == NULL)
                HapusAkhir();
        }
        if (head == NULL)
            printf("Linked list sudah kosong\n");
    }
}

int main()
{
    int pangkat, konstanta, pilih;
    char lagi = 'y';
    while (lagi == 'y' || lagi == 'Y')
    {
        printf("\n1. Sisip Urut\n");
        printf("2. Hapus\n");
        printf("Pilihan: ");
        fflush(stdin);
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            printf("\nMasukkan konstanta dan pangkat: ");
            scanf("%d %d", &konstanta, &pangkat);
            AlokasiSimpul(konstanta, pangkat);
            SisipUrut();
            break;

        case 2:
            if (head == NULL)
            {
                printf("\nLinked list masih kosong\n");
                break;
            }
            printf("\nMasukkan pangkat yang dihapus: ");
            scanf("%d", &pangkat);
            HapusUrut(pangkat);
            break;
            
        default:
            printf("\nPilihan tidak valid!");
        }
        Cetak();
        printf("Lagi? (y/t) ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
    return 0;
}