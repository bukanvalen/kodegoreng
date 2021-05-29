
#include <bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity, int &hits)
{
  unordered_set<int> s;
  unordered_map<int, int> indexes;
  int page_faults = 0;

  for (int i = 0; i < n; i++)
  {
    if (s.size() < capacity)
    {
      if (s.find(pages[i]) == s.end())
      {
        s.insert(pages[i]);

        page_faults++;
      }

      indexes[pages[i]] = i;
    }

    else
    {
      if (s.find(pages[i]) == s.end())
      {
        int lru = INT_MAX, val;
        for (auto it = s.begin(); it != s.end(); it++)
        {
          if (indexes[*it] < lru)
          {
            lru = indexes[*it];
            val = *it;
          }
        }

        s.erase(val);

        s.insert(pages[i]);

        page_faults++;
      }
      else
        hits++;

      indexes[pages[i]] = i;
    }
  }

  return page_faults;
}

int main()
{
  int i, capacity, n, page_faults, hits = 0;
  cout << "Masukkan jumlah frame: ";
  cin >> capacity;
  cout << "Masukkan jumlah page reference string: ";
  cin >> n;
  int pages[n];
  for (i = 0; i < n; i++)
  {
    cout << "Masukkan page reference string ke-" << i + 1 << ": ";
    cin >> pages[i];
  }
  
  page_faults = pageFaults(pages, n, capacity, hits);
  cout << "\nJumlah page fault = " << page_faults << endl;
  cout << "Jumlah hits = " << hits << endl;
  cout << "Page fault rate = " << (float)page_faults / capacity << " per frame";
  return 0;
}