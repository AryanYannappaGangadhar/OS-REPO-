#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    int base[n], limit[n];

    for(i = 0; i < n; i++) {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d%d", &base[i], &limit[i]);
    }

    int seg, offset;

    printf("Enter segment number and offset: ");
    scanf("%d%d", &seg, &offset);

    if(offset < limit[seg])
        printf("Physical Address = %d\n", base[seg] + offset);
    else
        printf("Invalid Offset\n");

    return 0;
}