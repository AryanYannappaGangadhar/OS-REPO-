#include <stdio.h>

int main() {
    int pages, frames, i, j, k = 0, flag, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int p[pages];
    printf("Enter page reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int f[frames];
    for(i = 0; i < frames; i++) f[i] = -1;

    for(i = 0; i < pages; i++) {
        flag = 0;
        for(j = 0; j < frames; j++) {
            if(f[j] == p[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            f[k] = p[i];
            k = (k + 1) % frames;
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);

    return 0;
}