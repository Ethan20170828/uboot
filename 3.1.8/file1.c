#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



int main(void)
{
	// 第零步：定义局部变量
	int fd = -1, ret = -1;				// fd : file descriptor，文件描述符
	char buf[100] = {0};
	char writebuf[20] = "I love linux";
	
	// 第一步：打开文件
	fd = open("a.txt", O_RDWR);
	if (-1 == fd)				// 有时候也写出：(fd < 0)
	{
		perror("open");
		_exit(-1);
	}
	else
	{
		printf("文件打开成功, fd = %d.\n", fd);
	}
	
	ret = lseek(fd, 3, SEEK_SET);
	printf("lseek, ret = %d.\n", ret);
	

	// 第二步：读写文件
#if 0
	// 写文件
	ret = write(fd, writebuf, strlen(writebuf));	// 用strlen函数来得到writebuf的大小
	if (ret < 0)
	{
		printf("write失败\n");
		_exit(-1);
	}
	else
	{
		printf("write 成功，写入了%d个字符\n", ret);
	}
#endif

#if 1
	// 读文件
	ret = read(fd, buf, 20);
	if (ret < 0)
	{
		printf("读取失败\n");
		_exit(-1);
	}
	else
	{
		printf("实际读取了%d个字节\n", ret);
		printf("文件内容是：[%s]\n", buf);
	}
#endif

	// 第三步：关闭文件
	close(fd);
	
	
	return 0;
}












