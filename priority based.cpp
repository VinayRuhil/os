#include <iostream>
using namespace std;

//#define MIN -9999

int main() {
    int n, l, ct = 0, remaining;
    int no[10], at[10], bt[10], wt[10], tat[10], pri[10], status[10];
    float avgtat = 0, avgwt = 0;

    cout << "<--Highest Priority First Scheduling Algorithm (Non-Preemptive)-->" << endl;
    cout << "Enter Number of Processes : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nProcess No: " << i + 1 << endl;
        no[i] = i + 1;

        cout << "Enter Arrival Time: ";
        cin >> at[i];

        cout << "Enter Burst Time: ";
        cin >> bt[i];

        cout << "Enter Priority: ";
        cin >> pri[i];

        status[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(pri[j], pri[j + 1]);
                swap(no[j], no[j + 1]);
            }
        }
    }

    pri[9] = MIN;
    remaining = n;

    cout << "\nProcessNo\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n";

    for (ct = at[0]; remaining != 0;) {
        l = 9;
        for (int i = 0; i < n; i++) {
            if (at[i] <= ct && status[i] != 1 && pri[i] > pri[l]) {
                l = i;
            }
        }

        ct += bt[l];
        tat[l] = ct - at[l];
        avgtat += tat[l];
        wt[l] = tat[l] - bt[l];
        avgwt += wt[l];
        status[l] = 1;
        remaining--;

        cout << "P" << no[l] << "\t\t" << at[l] << "\t" << bt[l] << "\t" << pri[l] << "\t"
             << ct << "\t" << tat[l] << "\t" << wt[l] << "\t" << wt[l] << endl;
    }

    avgtat /= n;
    avgwt /= n;

    cout << "\nAverage TurnAroundTime = " << avgtat << endl;
    cout << "Average WaitingTime = " << avgwt << endl;

    return 0;
}

