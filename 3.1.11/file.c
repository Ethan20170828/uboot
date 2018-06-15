#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



#define	FILENAME	"1.txt"


int main(void)
{
	int fd1 = -1, fd2 = -1;
	
	fd1 = open(FILENAME, O_RDWR | O_CREAT | O_TRUNC);
	if (fd1 < 0)
	{
		perror("open");
		return -1;
	}
	printf("fd1 = %d.\n", fd1);
	
	// 复制文件描述符
	fd2 = dup(fd1);
	printf("fd2 = %d.\n", fd2);
	
	return 0;
}






























