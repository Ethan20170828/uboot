#include <stdio.h>		// standrad input output
#include <string.h>

#define FILENAME	"1.txt"

int main(void)
{
	FILE *fp = NULL;
	size_t len = -1;
	//int array[10] = {1, 2, 3, 4, 5};
	char buf[100] = {0};
	
	fp = fopen(FILENAME, "r+");
	if (NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	printf("fopen success, fp = %p.\n", fp);
	
	memset(buf , 0, sizeof(buf));
	len = fread(buf, 1, 10, fp);
	
	printf("len = %ld.\n", len);
	printf("buf : [%s].\n", buf);
	
#if 0	
	fp = fopen(FILENAME, "w+");
	if (NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	printf("fopen success, fp = %p.\n", fp);
	
	// 在这里去读写文件
	//len = fwrite("abcde", 1, 5, fp);
	len = fwrite(array, sizeof(int), sizeof(array)/sizeof(array[0]), fp);
	printf("len = %ld.\n", len);
#endif
	fclose(fp);
	return 0;
}












