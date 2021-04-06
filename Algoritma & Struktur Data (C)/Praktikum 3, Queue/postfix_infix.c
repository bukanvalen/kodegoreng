#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSTACK 40
typedef int ItemType;

typedef struct
{
    ItemType item[MAXSTACK];
    int count;
} Stack;

void InisialisasiStack(Stack *s)
{
    s->count = 0;
}

int Kosong(Stack *s)
{
    return s->count == 0;
}

int Penuh(Stack *s)
{
    return s->count == MAXSTACK;
}

void Push(Stack *s, ItemType x)
{
    if (Penuh(s))
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
    if (Kosong(s))
        printf("Stack masih kosong!\n");
    else
    {
        s->count--;
        temp = s->item[s->count];
    }
    return temp;
}

int level(char oper)
{
    if (oper == '^')
        return 4;
    else if (oper == '*' || oper == '/')
        return 3;
    else if (oper == '+' || oper == '-')
        return 2;
    else if (oper == '(')
        return 1;
    else
        return 0;
}

int main()
{
    Stack t, r;
    char infix[MAXSTACK], temp, postfix[MAXSTACK];
    int i, j = 0, OpLeft, OpRight, hasil;

    InisialisasiStack(&t);
    InisialisasiStack(&r);

    printf("Masukkan notasi infix: ");
    scanf("%s", &infix);

    for (i = 0; i < strlen(infix); i++)
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
            postfix[j++] = infix[i];

        else if (infix[i] == '(')
            Push(&t, infix[i]);

        else if (infix[i] == ')')
        {
            while (t.item[t.count - 1] != '(')
                postfix[j++] = Pop(&t);

            temp = Pop(&t);
        }
        else if (infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-')
        {
            if (Kosong(&t) || level(t.item[t.count - 1] < level(infix[i])))
                Push(&t, infix[i]);

            else
            {
                while (level(t.item[t.count - 1]) >= level(infix[i]))
                    postfix[j++] = Pop(&t);

                Push(&t, infix[i]);
            }
        }

        else
            printf("Notasi salah\n");
    }

    while (!Kosong(&t))
        postfix[j++] = Pop(&t);

    postfix[j] = '\0';

    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            Push(&r, postfix[i] - 48);

        else if (postfix[i] == '^' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')
        {
            OpRight = Pop(&r);
            OpLeft = Pop(&r);

            if (postfix[i] == '^')
                hasil = (int)pow(OpLeft, OpRight);
            else if (postfix[i] == '*')
                hasil = OpLeft * OpRight;
            else if (postfix[i] == '/')
                hasil = (int)OpLeft / OpRight;
            else if (postfix[i] == '+')
                hasil = OpLeft + OpRight;
            else
                hasil = OpLeft - OpRight;

            Push(&r, hasil);
        }

        else
            printf("Notasi tidak dikenal\n");
    }

    while (!Kosong(&r))
        printf("\nInfix = %s\nPostfix = %s\nHasil = %d", infix, postfix, Pop(&r));

    return 0;
}