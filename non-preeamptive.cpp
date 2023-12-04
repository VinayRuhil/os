#include <iostream>

using namespace std;

void avg_time(int wt[] , int tat[] , int bt[] , int p[] , int n  ){
	float total = 0;
	float avg_wt , avg_tat;
	wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = (total) / n;
    total = 0;

	cout<<"\nSJF scheduling: \n";
    cout << "\nProcesses "<< " Burst time " << " Waiting time " << " Turn around time\n";
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        cout << "P" << p[i] << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
    }

    avg_tat = (total) / n;
    cout << "\nAverage Waiting Time = " << avg_wt << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;
}

int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, pos, temp;
    float avg_wt, avg_tat , total;
    
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Burst Time:" << endl;
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    avg_time(wt , tat , bt, p ,  n );

    return 0;
}

