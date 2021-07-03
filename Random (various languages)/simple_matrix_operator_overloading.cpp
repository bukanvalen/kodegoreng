// Original source code:
// https://www.tutorialride.com/cpp-operator-overloading-programs/addition-of-two-matrices-using-operator-overloading-c.htm
#include <iostream>
using namespace std;
#define baris 2
#define kolom 2

class Matrix
{
    int a[baris][kolom];

public:
    void input();
    void display();
    void operator+(Matrix x);
    void operator-(Matrix x);
    void operator*(Matrix x);
};

void Matrix::input()
{
    cout << "\nMasukkan elemen matrix " << baris << "x" << kolom << ": \n";
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            cin >> a[i][j];
}

void Matrix::display()
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Matrix::operator+(Matrix x)
{
    int mat[baris][kolom];

    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            mat[i][j] = a[i][j] + x.a[i][j];

    cout << "\nPenambahan matrix: \n";
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
            cout << mat[i][j] << "\t";

        cout << "\n";
    }
}

void Matrix::operator-(Matrix x)
{
    int mat[baris][kolom];

    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            mat[i][j] = a[i][j] - x.a[i][j];

    cout << "\nPengurangan matrix: \n";
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
            cout << mat[i][j] << "\t";
        
        cout << "\n";
    }
}

void Matrix::operator*(Matrix x)
{
    int mat[baris][kolom];

    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
        {
            mat[i][j] = 0;

            for (int k = 0; k < kolom; k++)
                mat[i][j] += a[i][k] * x.a[k][j];
        }
        
    cout << "\nPerkalian matrix: \n";
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
            cout << mat[i][j] << "\t";

        cout << "\n";
    }
}

int main()
{
    Matrix mat1, mat2;

    mat1.input();
    mat2.input();

    cout << "\nMatrix Pertama: \n\n";
    mat1.display();

    cout << "\nMatrix Kedua: \n\n";
    mat2.display();

    mat1 + mat2;
    mat1 - mat2;
    mat1 * mat2;

    return 0;
}