#include <stdio.h>

// Function to calculate waiting time
void waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
    
    // First process has 0 waiting time
    wait_time[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        wait_time[i] = burst_time[i-1] + wait_time[i-1];
    }
}

// Function to calculate turnaround time
void turnaroundtime(int n, int burst_time[], int wait_time[], int tat[]) {

    for (int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wait_time[i];
    }
}

// Function to calculate average time
void avgtime(int proc[], int n, int burst_time[]) {

    int wait_time[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Calculate waiting time
    waitingtime(proc, n, burst_time, wait_time);

    // Calculate turnaround time
    turnaroundtime(n, burst_time, wait_time, tat);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wait_time[i];
        total_tat += tat[i];

        printf("%d\t%d\t\t%d\t\t%d\n",
               proc[i], burst_time[i], wait_time[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {

    // Process IDs
    int proc[] = {1, 2, 3};

    // Burst times
    int burst_time[] = {5, 8, 12};

    int n = sizeof(proc) / sizeof(proc[0]);

    avgtime(proc, n, burst_time);

    return 0;
}