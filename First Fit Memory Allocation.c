#include <stdio.h>

int main() {
    int blocks[10], process[10], i, j, n, m;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("Enter number of processes: ");
    scanf("%d", &m);

    printf("Enter process sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &process[i]);

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(blocks[j] >= process[i]) {
                printf("Process %d allocated to block %d\n", i+1, j+1);
                blocks[j] -= process[i];
                break;
            }
        }
        if(j == n)
            printf("Process %d not allocated\n", i+1);
    }

    return 0;
}