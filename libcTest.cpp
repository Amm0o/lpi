#include<iostream>
#include<gnu/libc-version.h>
#include<stdlib.h>
int main (int argc, char** argv) {
	std::cout<< "This is just testing ldd\n";


	const char* pointerToVersion = gnu_get_libc_version();

	printf("Version from pointer: %s\n", pointerToVersion);

	printf("Gnu LIBC version: %s\n", gnu_get_libc_version());
	printf("Gnu LIBC release: %s\n", gnu_get_libc_release());

	return 0;

}
