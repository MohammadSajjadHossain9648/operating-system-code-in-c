#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

int main(void)
{
    int pfds[2];
    char buf[6];

    pipe(pfds);

    if (!fork()) {
        printf(" CHILD: reading to the pipe\n");
        read(pfds[1], buf, 6);
        pthread_t mainThreadId = pthread_self();
        printf("CHILD: exiting and the id is %ld\n", mainThreadId);
        wait(NULL);
    }
     else {
        printf("PARENT: writing from pipe\n");
        write(pfds[0], "hello" , 6);
        printf("PARENT: write \"hello\"\n");
        exit(0);
    }

    return 0;
}
