#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "no mode given\n");
        exit(1);
    }
    char *err;
    int mode = strtol(argv[1], &err, 8);
    if (err < 0) {
        perror(err);
        exit(1);
    }
    for (int i = 2; i < argc; i++) {
        if (chmod(argv[i], mode) < 0) {
            perror(argv[i]);
        }
    }
    exit(0);
}
