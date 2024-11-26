#include <unistd.h>
#include <iostream>

#define MAX_READ 20
int main (int argc, char** agrv) {


    char* buffer[MAX_READ];

    if (read(STDIN_FILENO, buffer, MAX_READ) == -1)
	perror("read");

    printf("This was the input data: %s\n", buffer);

    return 0;


}

