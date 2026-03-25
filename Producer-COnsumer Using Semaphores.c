#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 5, x = 0;

void producer() {
    mutex--;
    full++;
    empty--;
    x++;
    printf("Producer produces item %d\n", x);
    mutex++;
}

void consumer() {
    mutex--;
    full--;
    empty++;
    printf("Consumer consumes item %d\n", x);
    x--;
    mutex++;
}

int main() {
    int n, i;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        int choice;
        printf("\n1. Produce\n2. Consume\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            if(mutex == 1 && empty != 0)
                producer();
            else
                printf("Buffer Full\n");
        } else if(choice == 2) {
            if(mutex == 1 && full != 0)
                consumer();
            else
                printf("Buffer Empty\n");
        }
    }

    return 0;
}