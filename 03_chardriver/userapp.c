#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char buffer[50];	
	int fd;
	int length;
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}
	printf("write : %ld\n", write(fd, "hello world", sizeof("hello world")));	
		
	//set the file position to 0
	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	//buffer[length] = '\0';
	printf("Read:%s\t length:%d\n", buffer, length);
	close(fd);
}
