#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello from Parent";
    char read_msg[50];

    pipe(fd);

    if(fork() == 0) {
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
    } else {
        write(fd[1], write_msg, sizeof(write_msg));
    }

    return 0;
}