#include<iostream>
using namespace std;


void wait_time(int n, int bt[], int wt[])
{
	
	wt[0] = 0;
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i] + wt[i-1] ;
}


void turnaround_time(int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i+1] + wt[i];
}


void avg_time(int n, int bt[])
{
	int wt[n], tat[n];
	float avg_wt , avg_tat;

	
	wait_time(n, bt, wt);
	turnaround_time(n, bt, wt, tat);


	for (int i=0; i<n; i++)
	{
		avg_wt +=  wt[i];
		avg_tat += tat[i];
		cout << " " << i+1 << "\t\t" << bt[i+1] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
	}


	cout << "\nAverage waiting time = " << avg_wt / n;
	cout << "\nAverage turn around time = " << avg_tat / n;
}


int main()
{
	
	int n , bt[30];
	cout<<"Enter number of Processes : ";
	cin>>n;
	
	for(int i = 1; i<=n ; i++){
		cout<<"\nEnter Burst time of "<<i<<" process : ";
		cin>>bt[i];
	}
	
	cout << "\nProcesses "<< " Burst time " << " Waiting time " << " Turn around time\n";
	
	avg_time(n, bt);
	return 0;
}

