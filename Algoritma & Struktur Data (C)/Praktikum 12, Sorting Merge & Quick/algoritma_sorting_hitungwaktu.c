#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MAKS;

void insertion_data(int data[], int pilih)
{
  int i = 1;
  int key, j;
  while (i < MAKS)
  {
    key = data[i];
    j = i - 1;
    if (pilih == 1)
    {
      while (j >= 0 && data[j] > key)
      {
        data[j + 1] = data[j];
        j--;
      }
    }
    else if (pilih == 2)
    {
      while (j >= 0 && data[j] < key)
      {
        data[j + 1] = data[j];
        j--;
      }
    }
    data[j + 1] = key;
    i++;
  }
}

void selection_data(int data[], int pilih)
{
  int i = 0, min, maks, j, temp;
  while (i < MAKS - 1)
  {
    j = i + 1;
    if (pilih == 1)
    {
      min = i;
      while (j < MAKS)
      {
        if (data[j] < data[min])
          min = j;
        j++;
      }
      temp = data[i];
      data[i] = data[min];
      data[min] = temp;
    }
    else if (pilih == 2)
    {
      maks = i;
      while (j < MAKS)
      {
        if (data[j] > data[maks])
          maks = j;
        j++;
      }
      temp = data[i];
      data[i] = data[maks];
      data[maks] = temp;
    }
    i++;
  }
}

void bubble_data(int data[], int pilih)
{
  int i = 1, j, temp;
  while (i < MAKS - 1)
  {
    j = MAKS - 1;
    while (j >= 1)
    {
      if (pilih == 1)
      {
        if (data[j - 1] > data[j])
        {
          temp = data[j - 1];
          data[j - 1] = data[j];
          data[j] = temp;
        }
      }
      else if (pilih == 2)
      {
        if (data[j - 1] < data[j])
        {
          temp = data[j - 1];
          data[j - 1] = data[j];
          data[j] = temp;
        }
      }

      j--;
    }
    i++;
  }
}

void shell_data(int data[], int pilih)
{
  int i = 0, jarak = MAKS, j, temp, sudah;
  while (jarak > 1)
  {
    jarak = jarak / 2;
    sudah = 1;
    while (sudah == 1)
    {
      sudah = 0;
      j = 0;
      while (j < MAKS - jarak)
      {
        i = j + jarak;
        if (pilih == 1)
        {
          if (data[j] > data[i])
          {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
            sudah = 1;
          }
        }
        else if (pilih == 2)
        {
          if (data[j] < data[i])
          {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
            sudah = 1;
          }
        }
        j++;
      }
    }
  }
}

int partition(int arr[], int p, int r, int pilih)
{
  int i, j;
  int pivot, temp;
  pivot = arr[p];
  i = p;
  j = r;
  while (i <= j)
  {
    if (pilih == 1)
    {
      while (pivot < arr[j])
        j--;
      while (pivot > arr[i])
        i++;
    }
    else if (pilih == 2)
    {
      while (pivot > arr[j])
        j--;
      while (pivot < arr[i])
        i++;
    }
    if (i < j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j--;
      i++;
    }
    else
      return j;
  }
  return j;
}

void quick_data(int data[], int p, int r, int pilih)
{
  int q;
  if (p < r)
  {
    q = partition(data, p, r, pilih);
    quick_data(data, p, q, pilih);
    quick_data(data, q + 1, r, pilih);
  }
}

void merge(int arr[], int left, int median, int right, int pilih)
{
  int temp[MAKS];
  int kiri1, kanan1, kiri2, kanan2, i, j;
  kiri1 = left;
  kanan1 = median;
  kiri2 = median + 1;
  kanan2 = right;
  i = left;
  if (pilih == 1)
  {
    while ((kiri1 <= kanan1) && (kiri2 <= kanan2))
    {
      if (arr[kiri1] <= arr[kiri2])
      {
        temp[i] = arr[kiri1];
        kiri1++;
      }
      else
      {
        temp[i] = arr[kiri2];
        kiri2++;
      }
      i++;
    }
    while (kiri1 <= kanan1)
    {
      temp[i] = arr[kiri1];
      kiri1++;
      i++;
    }
    while (kiri2 <= kanan2)
    {
      temp[i] = arr[kiri2];
      kiri2++;
      i++;
    }
    j = left;
    while (j <= right)
    {
      arr[j] = temp[j];
      j++;
    }
  }

  else if (pilih == 2)
  {
    while ((kiri1 <= kanan1) && (kiri2 <= kanan2))
    {
      if (arr[kiri1] >= arr[kiri2])
      {
        temp[i] = arr[kiri1];
        kiri1++;
      }
      else
      {
        temp[i] = arr[kiri2];
        kiri2++;
      }
      i++;
    }
    while (kiri1 <= kanan1)
    {
      temp[i] = arr[kiri1];
      kiri1++;
      i++;
    }
    while (kiri2 <= kanan2)
    {
      temp[i] = arr[kiri2];
      kiri2++;
      i++;
    }
    j = left;
    while (j <= right)
    {
      arr[j] = temp[j];
      j++;
    }
  }
}

void merge_data(int data[], int l, int r, int pilih)
{
  int med;
  if (l < r)
  {
    med = (l + r) / 2;
    merge_data(data, l, med, pilih);
    merge_data(data, med + 1, r, pilih);
    merge(data, l, med, r, pilih);
  }
}

int main()
{
  printf("Masukkan jumlah data = ");
  scanf("%d", &MAKS);

  clock_t waktu;
  int awal[MAKS], i, data[MAKS], pilih;
  char lagi = 'y';

  for (i = 0; i < MAKS; i++)
  {
    srand(time(NULL) * (i + 1));
    awal[i] = rand() % 100 + 1;
  }

  while (lagi == 'y')
  {
    for (i = 0; i < MAKS; i++)
    {
      data[i] = awal[i];
    }

    printf("\n1. Insertion\n");
    printf("2. Selection\n");
    printf("3. Bubble\n");
    printf("4. Shell\n");
    printf("5. Quick\n");
    printf("6. Merge\n");
    printf("Masukkan Pilihan = ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
      printf("1. Ascending\n");
      printf("2. Descending\n");
      printf("Masukkan Pilihan = ");
      scanf("%d", &pilih);
      waktu = clock();
      insertion_data(data, pilih);
      waktu = clock() - waktu;
      break;

    case 2:
      printf("1. Ascending\n");
      printf("2. Descending\n");
      printf("Masukkan Pilihan = ");
      scanf("%d", &pilih);
      waktu = clock();
      selection_data(data, pilih);
      waktu = clock() - waktu;
      break;

    case 3:
      printf("1. Ascending\n");
      printf("2. Descending\n");
      printf("Masukkan Pilihan = ");
      scanf("%d", &pilih);
      waktu = clock();
      bubble_data(data, pilih);
      waktu = clock() - waktu;
      break;

    case 4:
      printf("1. Ascending\n");
      printf("2. Descending\n");
      printf("Masukkan Pilihan = ");
      scanf("%d", &pilih);
      waktu = clock();
      shell_data(data, pilih);
      waktu = clock() - waktu;
      break;

    case 5:
      printf("1. Ascending\n");
      printf("2. Descending\n");
      printf("Masukkan Pilihan = ");
      scanf("%d", &pilih);
      waktu = clock();
      quick_data(data, 0, MAKS - 1, pilih);
      waktu = clock() - waktu;
      break;

    case 6:
      printf("1. Ascending\n");
      printf("2. Descending\n");
      printf("Masukkan Pilihan = ");
      scanf("%d", &pilih);
      waktu = clock();
      merge_data(data, 0, MAKS - 1, pilih);
      waktu = clock() - waktu;
      break;

    default:
      printf("Menu tidak tersedia\n");
      break;
    }

    printf("\nWaktu yang dibutuhkan untuk menjalankan proses = %f\n", ((double)waktu) / CLOCKS_PER_SEC);
    fflush(stdin);

    printf("Ingin lanjut lagi (y/t) ? ");
    scanf("%c", &lagi);
  }
  return 0;
}