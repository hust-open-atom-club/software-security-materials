#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void read_flag(char *buf)
{
	int fd = open("./flag", 0);
	read(fd, buf, 0x100);
}

int main()
{
	setbuf(stdout, NULL);

	char *a = malloc(0x18);
	memset(a, 0, 0x10);
	// 生成悬挂指针 a
	free(a);
	printf("Here is a dangling pointer a\n");
	char *b = malloc(0x18);
	// 读取 flag 至 b 所指向的内存区域
	printf("Read key flag into buffer b\n");
	read_flag(b);
	// UAF 读取新分配对象 b 的内容
	printf("UAF leak the content of b\n");
	puts(a);
	// UAF 修改新分配对象 b 的内容
	printf("UAF overwrite the content of b\n");
	memset(a, 0x41, 0x8);
	puts(b);

	return 0;
}
