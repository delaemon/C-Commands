#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s second\n", argv[0]);
        exit(1);
    }

    int second = atoi(argv[1]);
    sleep(second);
    exit(0);
}
