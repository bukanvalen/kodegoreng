#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct
{
    int NRP;
    char nama[30];
    int nilai;
} MHS;

typedef struct
{
    MHS item[MAX];
    int front;
    int rear;
    int count;
} Queue;

int QueuePenuh(Queue *q)
{
    return (q->count == MAX);
}

int QueueKosong(Queue *q)
{
    return (q->count == 0);
}

void InisialisasiQueue(Queue *q)
{
    q->front = q->rear = q->count = 0;
}

void Enqueue(Queue *q, MHS x)
{
    if (QueuePenuh(q))
        printf("Stack penuh.\n");

    else
    {
        q->item[q->rear].NRP = x.NRP;
        strcpy(q->item[q->rear].nama, x.nama);
        q->item[q->rear].nilai = x.nilai;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

MHS Dequeue(Queue *q)
{
    MHS temp;

    temp.NRP = -1;
    strcpy(temp.nama, " ");
    temp.nilai = -1;

    if (QueueKosong(q))
        printf("Queue kosong.\n");

    else
    {
        temp.NRP = q->item[q->front].NRP;
        strcpy(temp.nama, q->item[q->front].nama);
        temp.nilai = q->item[q->front].nilai;
        q->front = (q->front + 1) % MAX;
        q->count--;
    }

    return temp;
}

void UrutkanQueue(Queue *q)
{
    MHS temp;

    temp.NRP = -1;
    strcpy(temp.nama, " ");
    temp.nilai = -1;

    int i, j, n = q->count;

    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (q->item[i].nilai < q->item[j].nilai)
            {
                temp.NRP = q->item[i].NRP;
                strcpy(temp.nama, q->item[i].nama);
                temp.nilai = q->item[i].nilai;

                q->item[i].NRP = q->item[j].NRP;
                strcpy(q->item[i].nama, q->item[j].nama);
                q->item[i].nilai = q->item[j].nilai;

                q->item[j].NRP = temp.NRP;
                strcpy(q->item[j].nama, temp.nama);
                q->item[j].nilai = temp.nilai;
            }
        }
    }
}

void TampilQueue(Queue *q)
{
    int i = q->front;

    printf("\nNRP\tNama\tNilai\n");

    while (i != q->rear)
    {
        printf("%d\t%s\t%d\n", q->item[i].NRP, q->item[i].nama, q->item[i].nilai);
        i = (i + 1) % MAX;
    }
}

int main()
{
    Queue q, cetak;
    MHS mhs;
    int i, hitung = 0;
    char lagi = 'Y';

    InisialisasiQueue(&q);
    InisialisasiQueue(&cetak);

    do
    {
        mhs.NRP = -1;
        printf("\nMasukkan NRP mahasiswa: ");
        scanf("%d", &mhs.NRP);
        fflush(stdin);

        if (mhs.NRP == -1)
        {
            printf("\n* terdeteksi, data mahasiswa akan di-dequeue");
            Enqueue(&cetak, Dequeue(&q));
            UrutkanQueue(&cetak);
            printf("\nDaftar queue cetak saat ini: ");
            TampilQueue(&cetak);
        }

        else
        {
            printf("Masukkan nama mahasiswa: ");
            gets(mhs.nama);
            printf("Masukkan nilai mahasiswa: ");
            scanf("%d", &mhs.nilai);
            fflush(stdin);
            Enqueue(&q, mhs);
        }

        if (++hitung == MAX)
            break;

        printf("\nIngin memasukkan lagi? (Y/T)\n");
        scanf("%c", &lagi);
    } while (lagi == 'Y' || lagi == 'y');

    TampilQueue(&q);

    return 0;
}