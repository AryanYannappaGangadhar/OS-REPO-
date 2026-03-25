#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *myfifo = "myfifo";
    char msg[100];

    mkfifo(myfifo, 0666);

    fd = open(myfifo, O_WRONLY);
    printf("Enter message: ");
    scanf("%s", msg);

    write(fd, msg, sizeof(msg));
    close(fd);

    return 0;
}