#include <stdio.h>

int main() {
    int n;
    int pid[25], priority[25], at[25], bt[25], ct[25], tat[25], wt[25];
    int i, j, temp;

    // Input the number of processes
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    // Input priority for each process
    printf("Enter the priority for each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i;
        printf("P[%d]: ", i);
        scanf("%d", &priority[i]);
    }

    // Input arrival time for each process
    printf("Enter the Arrival time for each process (in ms):\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        scanf("%d", &at[i]);
        wt[i] = tat[i] = 0; // Initialize waiting time and turnaround time
    }

    // Input burst time for each process
    printf("Enter the Burst time for each process (in ms):\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        scanf("%d", &bt[i]);
    }

    // Sort by priority (bubble sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priority
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap arrival time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process ID
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Move the process with the earliest arrival time to the front
    int min = 0;
    for (i = 0; i < n; i++) {
        if (at[i] < at[min]) {
            min = i;
        }
    }
    temp = pid[min];
    for (j = min - 1; j >= 0; j--) {
        pid[j + 1] = pid[j];
    }
    pid[0] = temp;

    // Calculate completion time, turnaround time, and waiting time
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    
    // Print table of process details
    printf("\n------------------------------------------------------------------------\n");
    printf("| PID | ARRIVAL TIME | BURST TIME | COMPLETION TIME | TURNAROUND TIME | WAITING TIME |\n");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("| %3d | %12d | %10d | %15d | %15d | %12d |\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("------------------------------------------------------------------------\n");

    // Calculate and print average turnaround time and waiting time
    int sum_tat = 0, sum_wt = 0;
    for (i = 0; i < n; i++) {
        sum_tat += tat[i];
        sum_wt += wt[i];
    }
    printf("\nAverage Waiting Time = %.2f ms\n", (float)sum_wt / n);
    printf("Average Turnaround Time = %.2f ms\n", (float)sum_tat / n);

    return 0;
}