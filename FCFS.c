#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time by adding burst time and waiting time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // Function to find turnaround time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with their burst times
    printf("Processes   Burst Time   Waiting Time   Turn-Around Time\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate average waiting time and average turnaround time
    printf("Average waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turn-around time = %.2f", (float)total_tat / (float)n);
}

int main() {
    int processes[] = {1, 2, 3}; // Process IDs
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes

    int burst_time[] = {10, 5, 8}; // Burst time of all processes

    findAverageTime(processes, n, burst_time);

    return 0;
}
