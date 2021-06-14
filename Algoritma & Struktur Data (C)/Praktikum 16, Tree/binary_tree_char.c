#include <stdio.h>
#include <stdlib.h>
typedef char TypeInfo;
typedef struct Simpul *Tree;

struct Simpul
{
  TypeInfo Info;
  Tree Kiri, Kanan;
};

Tree baru(char hrf)
{
  Tree br;
  br = (Tree)malloc(sizeof(struct Simpul));
  br->Info = hrf;
  br->Kiri = NULL;
  br->Kanan = NULL;
  return (br);
};

void sisip(Tree ph, Tree sp)
{
  Tree P, Q;
  P = ph;
  Q = ph;
  while ((sp->Info != ph->Info) && (Q != NULL))
  {
    P = Q;
    if (sp->Info < P->Info)
      Q = P->Kiri;
    else
      Q = P->Kanan;
  }
  if (sp->Info == P->Info)
    printf("Sudah ada\n");
  else if (sp->Info < P->Info)
    P->Kiri = sp;
  else
    P->Kanan = sp;
};

void preorder(Tree ph)
{
  if (ph != NULL)
  {
    printf("%c ", ph->Info);
    preorder(ph->Kiri);
    preorder(ph->Kanan);
  }
};

void inorder(Tree ph)
{
  if (ph != NULL)
  {
    inorder(ph->Kiri);
    printf("%c ", ph->Info);
    inorder(ph->Kanan);
  }
};

void postorder(Tree ph)
{
  if (ph != NULL)
  {
    postorder(ph->Kiri);
    postorder(ph->Kanan);
    printf("%c ", ph->Info);
  }
};

int ukuran(Tree ph)
{
  static int size = 0;
  if (ph != NULL)
  {
    ukuran(ph->Kiri);
    ukuran(ph->Kanan);
    size++;
  }
  else
    return size;
};

int kedalaman(Tree ph)
{
  int kedalamanKiri, kedalamanKanan, kedalaman_max;
  if (ph == NULL)
    return 0;
  else
  {
    kedalamanKiri = kedalaman(ph->Kiri);
    kedalamanKanan = kedalaman(ph->Kanan);
    if (kedalamanKiri > kedalamanKanan)
      kedalaman_max = kedalamanKiri + 1;
    else
      kedalaman_max = kedalamanKanan + 1;
    return kedalaman_max;
  }
};

int main()
{
  Tree br, ph = NULL;
  char ch, lagi = 'y';
  while (lagi == 'y' || lagi == 'Y')
  {
    fflush(stdin);
    printf("Masukkan karakter: ");
    scanf("%c", &ch);
    br = baru(ch);
    (ph == NULL) ? ph = br : sisip(ph, br);
    fflush(stdin);
    printf("Lagi? (Y/T) << ");
    scanf("%c", &lagi);
  }
  printf("\nTraversal >>\n1. Preorder: ");
  preorder(ph);
  printf("\n2. Inorder  ");
  inorder(ph);
  printf("\n3. Postorder: ");
  postorder(ph);
  printf("\n\nInformasi Tree >>\n- Ukuran tree: %d", ukuran(ph));
  printf("\n- Kedalaman: %d", kedalaman(ph));
  return 0;
}