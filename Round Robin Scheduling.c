#include <stdio.h>

int main() {
    int n, i, time = 0, remain;
    int burst[20], rem_bt[20], waiting[20], turnaround[20], tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
        rem_bt[i] = burst[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                if(rem_bt[i] <= tq) {
                    time += rem_bt[i];
                    waiting[i] = time - burst[i];
                    rem_bt[i] = 0;
                    remain--;
                } else {
                    rem_bt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    for(i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
    }

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", i+1, waiting[i], turnaround[i]);
    }

    return 0;
}