
#include <iostream>
#include <cstring>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j, allocation[n], fragments[m];
    
    memset(allocation, -1, sizeof(allocation));
    memset(fragments, -1, sizeof(fragments));
        
    for (i = 0; i < n; i++)
    {        
        int bestIdx = -1;
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || (blockSize[bestIdx] > blockSize[j]))
                    bestIdx = j;
            }
        }
        
        if (bestIdx != -1)
        {            
            allocation[i] = bestIdx;
            
            blockSize[bestIdx] -= processSize[i];
            fragments[i] = blockSize[bestIdx];
        }
    }

    cout << "\nNo. Proses\tUkuran Proses\tNo. Partisi\tFragmentasi\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << "B" << allocation[i] + 1 << "\t\t" << fragments[i];
        else
            cout << ">> Tidak teralokasikan <<";
        cout << endl;
    }
}

int main()
{                
    int i, n, m;

    cout << "Masukkan jumlah proses: ";
    cin >> n;
    int processSize[n];
    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << " = ";
        cin >> processSize[i];
    }


    cout << "\nMasukkan jumlah partisi: ";
    cin >> m;
    int blockSize[m];
    for (i = 0; i < m; i++)
    {
        cout << "B" << i + 1 << " = ";
        cin >> blockSize[i];
    }

    bestFit(blockSize, m, processSize, n);

    return 0;
}