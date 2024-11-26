#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char** argv) {

    // Check for the parameters being passed
    if(argc != 3 || std::strcmp(argv[1], "--help") == 0) {
	printf("Error in the arguments being passed in.\nExample usage: ./copy /home/usr/file.txt /home/usr/dst.txt\n");
	return -1;
    }


    // Get fd from src file
    int src_fd = open(argv[1], O_RDONLY); // Don't need to pass mode since file is already created and want to only read from it

    // Check for errors
    if(src_fd == -1) {
	perror("open");
	printf("Error getting the fd to read from src file");
    }

    // Get fd for dst file
    // Setting flag
    int open_flags = O_CREAT | O_WRONLY | O_TRUNC;
    mode_t file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // Setting permissions to rw-rw-rw 

    int dst_fd = open(argv[2], open_flags, file_perms);

    if(dst_fd == -1) {
	perror("open");
	printf("Error getting fd for the dst file");
	return -1;
    }


    // Now transfer the data from one file to the other until we reach end of file
    char buff[BUF_SIZE];
    ssize_t read_return;
    while((read_return = read(src_fd, buff, BUF_SIZE)) > 0)
	if(write(dst_fd, buff, read_return) != read_return)
	    perror("write");

    // Check for errors in read()
    if(read_return == -1) 
	perror("read");

    // Close handles on files
    if(close(src_fd) == -1) perror("close src_fd");
    if(close(dst_fd) == -1) perror("close dst_fd");


    return 0;

    


}
