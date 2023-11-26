#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	unsigned long stack_var[0x10] = {0};
	unsigned long *chunk_lis[0x10] = {0};
	unsigned long *target;

	setbuf(stdout, NULL);

	// 1. start
	unsigned long *a = malloc(0x410);
	//防止堆块a释放后被合并至 topchunk
	unsigned long *b = malloc(0x20);

	printf("Chunk a point to %p\n", a);

	free(a);
	//分配一个比堆块a更大的堆块，使其残留libc地址与堆地址 
	unsigned long *c = malloc(0x430);
	for (int i = 0; i < 4; i++) {
		printf("%p | 0x%lx\n", a + i, *(a + i));
	}
	// 1. end

	// 2. start
	unsigned long *d = malloc(0x20);
	printf("Chunk b point to %p\n", b);
	printf("Chunk d point to %p\n", d);
	free(b);
	free(d);
	printf("UAF overwrite next pointer at d\n");
	printf("To  corrupt the allocation of b\n");
	// UAF 覆写 next 指针，从而劫持堆块的分配
	d[0] = a[2] + 0x10;
	malloc(0x20);
	b = malloc(0x20);
	printf("Dangling pointer %p\n", d);
	printf("Chunk b point to %p\n", b);
	// 此时，利用悬挂指针 d 进行写操作
	// 相当于修改 b 所指向内存区域
	assert(b == d);
	// 2. end

	return 0;
}
