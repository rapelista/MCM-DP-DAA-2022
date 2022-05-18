#include <iostream>
using namespace std;

void MCM(int **, int **, int *, int);
void optimalParens(int **, int i, int j);
void print(int **, int);

int main()
{
    int size;
    cout << "Masukkan jumlah matrix\t: ";
    cin >> size;

    size += 1;

    int *array = new int[size];
    int **m = new int *[size];
    int **s = new int *[size];

    cout << "Masukkan list dimensi\t: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];

    MCM(m, s, array, size);

    cout << "\nMatrix M:" << endl;
    print(m, size);

    cout << "\nMatrix S:" << endl;
    print(s, size);

    cout << "\nHasil Perkurungan Perkalian Optimal" << endl;
    optimalParens(s, 1, size - 1);
    cout << endl;
}

void MCM(int **m, int **s, int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        m[i] = new int[n];
        s[i] = new int[n];

        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++)
    {
        for (int i = 1, j = i + l - 1; i < n - l + 1; i++, j = i + l - 1)
        {
            m[i][j] = 2147483647; // di buku infinite, jadi pakai INT_MAX
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void optimalParens(int **s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        optimalParens(s, i, s[i][j]);
        optimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void print(int **arr, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j < n; j++)
        {
            if (j > i)
                continue;
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }
}