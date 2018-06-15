#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int cal_len(const char *pathname)
{
	// 第零步：定义局部变量
	int fd = -1, ret = -1;				// fd : file descriptor，文件描述符
	
	// 第一步：打开文件
	fd = open(pathname, O_RDONLY);
	if (-1 == fd)				// 有时候也写出：(fd < 0)
	{
		perror("open");
		return -1;
	}
	
	// 此时文件指针指向文件开头
	// 用lseek将文件指针移动到末尾，然后返回值就是文件指针距离文件开头的偏移量，也就是文件的长度了
	ret = lseek(fd, 0, SEEK_END);
	
	return ret;
}

int main(int argc, char **argv)
{
	// 第零步：定义局部变量
	int fd = -1, ret = -1;				// fd : file descriptor，文件描述符

	if (argc != 2)
	{
		printf("usage: %s filename\n", argv[0]);
		return -1;
	}
	
	printf("文件长度是：%d个字节\n", cal_len(argv[1]));
	
	return 0;
}









