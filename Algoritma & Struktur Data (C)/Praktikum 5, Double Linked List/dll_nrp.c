#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul DNode;

struct simpul
{
    int NRP;
    char nama[20];
    int nilai;
    DNode *next;
    DNode *prev;
};

DNode *head = NULL, *tail = NULL, *baru;

void AlokasiSimpul(int x, char nama[], int nilai)
{
    baru = (DNode *)malloc(sizeof(DNode));

    if (baru == NULL)
    {
        printf("Alokasi Memori Gagal");
        exit(1);
    }

    else
    {
        baru->NRP = x;
        strcpy(baru->nama, nama);
        baru->nilai = nilai;
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

void hitungMean()
{
    DNode *p = head;
    float jumlah = 0, total = 0;

    if (Kosong())
        return;

    while (p != NULL)
    {
        total += p->nilai;
        jumlah++;
        p = p->next;
    }

    printf("\nRata-rata nilai keseluruhan: %g\n", total / jumlah);
}

void Cetak()
{
    DNode *p = head;

    if (Kosong())
        return;

    printf("\nCetak head - tail:\n");
    printf("NRP\tNama\tNilai\n");
    while (p != NULL)
    {
        printf("%d\t%s\t%d\n", p->NRP, p->nama, p->nilai);
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
    printf("NRP\tNama\tNilai\n");
    while (p != NULL)
    {
        printf("%d\t%s\t%d\n", p->NRP, p->nama, p->nilai);
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

    while (before->NRP != x)
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

    while (after->NRP != x)
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
    while (hapus->NRP != x)
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

    else if (head->NRP > baru->NRP)
        SisipAwal();

    else
    {
        while (cek != NULL && cek->NRP < baru->NRP)
            cek = cek->next;

        if (cek == NULL)
            SisipAkhir();

        else if (cek->NRP == baru->NRP)
            printf("\nData dengan NRP yang ingin disisipkan sudah ada\n");

        else
            SisipSebelum(cek->NRP);
    }
}

void Hapus(int x)
{
    DNode *cek = head;

    if (head == tail)
        head = tail = NULL;

    else
    {
        if (head->NRP == x)
            HapusAwal();

        else if (tail->NRP == x)
            HapusAkhir();

        else
        {
            while (cek != NULL && cek->NRP != x)
            {
                cek = cek->next;

                if (cek == NULL)
                {
                    printf("\nNRP yang ingin dihapus tidak ada\n");
                    return;
                }
            }

            if (cek->NRP == x)
                HapusTengah(x);
        }
    }

    if (Kosong())
        printf("\nLinked list sudah kosong\n");
}

void Swap(DNode *a, DNode *b)
{
    b->nilai = a->nilai;
    strcpy(b->nama, a->nama);
}

void Update(int x)
{
    DNode *cek = head;

    if (x == head->NRP && x == tail->NRP)
        head = tail = baru;

    else
    {
        if (head->NRP == x)
            Swap(baru, head);

        else if (tail->NRP == x)
            Swap(baru, tail);

        else
        {
            while (cek != NULL && cek->NRP != x)
            {
                cek = cek->next;

                if (cek == NULL)
                {
                    printf("\nData dengan NRP yang ingin diupdate tidak ada\n");
                    return;
                }
            }

            if (cek->NRP == x)
                Swap(baru, cek);
        }
    }

    if (Kosong())
        printf("\nLinked list sudah kosong\n");
}

int main()
{
    int pilih, dt, nilai;
    char nama[20], lagi = 'y';

    printf("1. Sisip urut\n");
    printf("2. Hapus\n");
    printf("3. Update\n");
    printf("4. Hitung rata-rata nilai\n");

    while (lagi == 'y' || lagi == 'Y')
    {
        printf("\nPilihan: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            printf("\nMasukkan NRP: ");
            scanf("%d", &dt);
            fflush(stdin);
            printf("Masukkan nama: ");
            gets(nama);
            printf("Masukkan nilai: ");
            scanf("%d", &nilai);
            AlokasiSimpul(dt, nama, nilai);
            SisipUrut();
            break;

        case 2:
            if (Kosong())
            {
                printf("\nLinked list masih kosong\n");
                break;
            }
            printf("\nMasukkan NRP: ");
            scanf("%d", &dt);
            Hapus(dt);
            break;

        case 3:
            if (Kosong())
            {
                printf("\nLinked list masih kosong\n");
                break;
            }
            printf("\nMasukkan NRP: ");
            scanf("%d", &dt);
            fflush(stdin);
            printf("Masukkan nama: ");
            gets(nama);
            printf("Masukkan nilai: ");
            scanf("%d", &nilai);
            AlokasiSimpul(dt, nama, nilai);
            Update(dt);
            break;

        case 4:
            if (Kosong())
            {
                printf("\nLinked list masih kosong\n");
                break;
            }
            hitungMean();
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