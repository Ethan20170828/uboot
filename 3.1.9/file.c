#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



int main(void)
{
	// 第零步：定义局部变量
	int fd1 = -1, fd2 = -1, ret = -1;				// fd : file descriptor，文件描述符
	char buf[100] = {0};
	char writebuf[20] = "abcd";
	
	// 第一步：打开文件
	fd1 = open("a.txt", O_RDWR | O_TRUNC | O_CREAT, 0666);
	fd2 = open("a.txt", O_RDWR | O_TRUNC | O_CREAT, 0666);
	if ((-1 == fd1) || (-1 == fd2))				// 有时候也写出：(fd < 0)
	{
		perror("open");
		_exit(-1);
	}
	else
	{
		printf("文件打开成功, fd1 = %d, fd2 = %d.\n", fd1, fd2);
	}

	// 第二步：读写文件
#if 1
	// 写文件
	while (1)
	{
		//memset(writebuf, 0, sizeof(writebuf));
		ret = write(fd1, "ab", 2);	// 用strlen函数来得到writebuf的大小
		if (ret < 0)
		{
			printf("write失败\n");
			_exit(-1);
		}
		else
		{
			printf("write 成功，写入了%d个字符\n", ret);
		}
		
		sleep(1);

		//memset(writebuf, 0, sizeof(writebuf));
		ret = write(fd2, "cd", 2);	// 用strlen函数来得到writebuf的大小
		if (ret < 0)
		{
			printf("write失败\n");
			_exit(-1);
		}
		else
		{
			printf("write 成功，写入了%d个字符\n", ret);
		}
	}
	
#endif

#if 0
	while(1)
	{
		// 读文件
		memset(buf, 0, sizeof(buf));
		ret = read(fd1, buf, 2);
		if (ret < 0)
		{
			printf("读取失败\n");
			_exit(-1);
		}
		else
		{
			printf("fd1：[%s]\n", buf);
		}
		
		sleep(1);
		
		// 读文件
		memset(buf, 0, sizeof(buf));
		ret = read(fd2, buf, 2);
		if (ret < 0)
		{
			printf("读取失败\n");
			_exit(-1);
		}
		else
		{
			printf("fd2：[%s]\n", buf);
		}
	}
#endif

	// 第三步：关闭文件
	close(fd1);
	close(fd2);
	
	
	return 0;
}













