#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int bss_var;
int data_var = 200;

void text_var(void){
	printf("Test Func!\n");
}

int main(int argc,char *argv[]){
	int stack_var;
	int fd;
	int *heap_var;
	void *mmap_var;

	fd = open("1.txt",O_CREAT|O_RDWR,0777);
	mmap_var = mmap(NULL,4096,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	munmap(mmap_var,4096);
	heap_var = malloc(16);

	printf("stack_var: %p\n ",&stack_var);
	printf("mmap_var: %p\n ",mmap_var);
	printf("heap_var: %p\n ",heap_var);
	printf("bss_var: %p\n ",&bss_var);
	printf("data_var: %p\n ",&data_var);	
	printf("text_var: %p\n ",&text_var);
	
	return 0;
}
