#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

static uid_t get_user_id(char *user);

int main(int argc, char *argv[]) {
    uid_t uid;
    if (argc < 2)  {
        fprintf(stderr, "no user name give\n");
        exit(1);
    }
    uid = get_user_id(argv[1]);
    for (int i = 2; i < argc; i++) {
        if (chown(argv[i], uid, -1) < 0) {
            perror(argv[i]);
        }
    }
    exit(1);
}

static uid_t get_user_id(char *user) {
    struct passwd *pw;
    pw = getpwnam(user);
    if (!pw) {
        fprintf(stderr, "no such user: %s\n", user);
        exit(1);
    }
    return pw->pw_uid;
}
