#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10
typedef int ItemType;

typedef struct
{
  ItemType item[MAX];
  int count;
} Stack;

void InisialisasiStack(Stack *s)
{
  s->count = 0;
}

int StackKosong(Stack *s)
{
  return s->count == 0;
}

int StackPenuh(Stack *s)
{
  return s->count == MAX;
}

void Push(Stack *s, ItemType x)
{
  if (StackPenuh(s))
    printf("Stack penuh! Data tidak dapat masuk!\n");

  else
  {
    s->item[s->count] = x;
    s->count++;
  }
}

ItemType Pop(Stack *s)
{
  ItemType temp = -1;
  if (StackKosong(s))
    printf("Stack masih kosong!\n");

  else
  {
    s->count--;
    temp = s->item[s->count];
  }
  return temp;
}

////////////////////////////////////////////

typedef struct
{
  ItemType item[MAX];
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

void Enqueue(Queue *q, ItemType x)

{
  if (QueuePenuh(q))
    printf("Stack Penuh\n");

  else
  {
    q->item[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
  }
}

ItemType Dequeue(Queue *q)
{
  ItemType temp = -1;

  if (QueueKosong(q))
    printf("Queue kosong\n");

  else
  {
    temp = q->item[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
  }

  return temp;
}

void TampilQueue(Queue *q)
{
  int i = q->front;

  while (i != q->rear)
  {
    printf("%d ", q->item[i]);
    i = (i + 1) % MAX;
  }
}

int main()
{
  Queue q;
  Stack s;
  int i, input, pilih, no_parkir = 1;

  char lagi = 'Y';

  InisialisasiQueue(&q);
  InisialisasiStack(&s);

  do
  {
    printf("\nInput 1 untuk memasukkan mobil atau 2 untuk mengeluarkan mobil: ");
    scanf("%d", &pilih);
    fflush(stdin);

    if (pilih == 1)
    {
      printf("\nMobil dengan nomor parkir %d berhasil masuk ke dalam parkiran.", no_parkir);
      Enqueue(&q, no_parkir++);
    }

    else if (pilih == 2)
    {
      printf("\nMasukkan nomor parkir mobil yang ingin dikeluarkan: ");
      scanf("%d", &input);

      if (q.item[q.front] == input)
        printf("Mobil dengan nomor parkir %d keluar dari parkiran.", Dequeue(&q));

      else
      {
        printf("Mobil dengan nomor parkir %d keluar dari parkiran.", input);

        while (q.item[q.front] != input)
          Push(&s, Dequeue(&q));

        input = Dequeue(&q);

        while (!StackKosong(&s))
        {
          q.item[(q.front - 1) % MAX] = Pop(&s);
          q.front = (q.front - 1) % MAX;
          q.count++;
        }
      }
    }

    else
      printf("\nOpsi yang Anda masukkan salah.");

    printf("\n\nIsi parkiran saat ini:\n");

    printf("<--- Keluar\t");
    TampilQueue(&q);
    printf("\t<--- Masuk ");

    fflush(stdin);
    printf("\n\nApakah Anda ingin mengulang? (Y atau T) ");
    scanf("%c", &lagi);
    fflush(stdin);
  } while (lagi == 'Y' || lagi == 'y');

  return 0;
}