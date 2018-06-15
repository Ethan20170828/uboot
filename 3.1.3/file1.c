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
		printf("文件打开错误\n");
		return -1;
	}
	else
	{
		printf("文件打开成功, fd = %d.\n", fd);
	}
	
	// 第二步：读写文件
	// 写文件
	ret = write(fd, writebuf, strlen(writebuf));	// 用strlen函数来得到writebuf的大小
	if (ret < 0)
	{
		printf("write失败\n");
		return -1;
	}
	else
	{
		printf("write 成功，写入了%d个字符\n", ret);
	}
	
	// 读文件
	ret = read(fd, buf, sizeof(buf));
	if (ret < 0)
	{
		printf("读取失败\n");
		return -1;
	}
	else
	{
		printf("实际读取了%d个字节\n", ret);
		printf("文件内容是：[%s]\n", buf);
	}
	
	// 第三步：关闭文件
	close(fd);
	
	
	return 0;
}












