#include <stdio.h>
#include <stdbool.h>

void WaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n], i = 0;

    for (i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;

    while (1)
    {
        bool done = true;

        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;

                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }

                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == true)
            break;
    }
}

void AvrgWaitTime(int processes[], int n, int bt[], int quantum)
{
    int wt[n], total_wt = 0, i = 0;

    WaitingTime(processes, n, bt, wt, quantum);

    printf("-----------------------------------------------\n");
    printf("Proses ke-\t| Burst time\t| Waiting time\n");
    printf("-----------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];

        printf("%d\t\t| %d\t\t| %d\n", (i + 1), bt[i], wt[i]);
    }
    printf("-----------------------------------------------\n");

    printf("Rata-rata waktu tunggu = %g", (float)total_wt / (float)n);
}

int main()
{
    int jumlah, i, quantum, a = 1;

    printf("Masukkan jumlah proses = ");
    scanf("%d", &jumlah);
    printf("\n");

    int processes[jumlah], burst_time[jumlah];

    for (i = 0; i < jumlah; i++)
    {
        printf("Masukkan P[%d] = ", a);
        scanf("%d", &burst_time[i]);
        processes[a] = a;
        a++;
    }

    printf("\nMasukkan nilai quantum = ");
    scanf("%d", &quantum);
    printf("\n");

    AvrgWaitTime(processes, jumlah, burst_time, quantum);
    return 0;
}