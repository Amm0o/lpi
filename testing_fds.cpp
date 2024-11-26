#include<iostream>
#include<fcntl.h>


int main(int argc, char** argv) {
	
	if (argc < 1 || argc > 2) {
		printf("We just accept one argument and it has to be the path for the file\n Example: ./program /path/to/file.txt\n");
		return -1;
	}

	const char* file_to_open = argv[1];

	printf("We are getting fd for file: %s\n", file_to_open);



	// Getting a file descriptor
	int test_file_descriptor = open(file_to_open, O_WRONLY);

	if(test_file_descriptor == -1) {
		perror("open"); // Get error for syscall open(2)
		printf("Error getting fd\n");
		return -1;
	}

	printf("This is the file descriptor: %d\n", test_file_descriptor);

	return 0;
}
