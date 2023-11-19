#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void never_invoke(){
	puts("I will be never invoked :(");
}

int vuln_func()
{
	char buffer[30];
	int m = 3;
	scanf("%s", buffer); // vulnerable scanf
	return 0;
}

int main(int argc, char* argv[]) 
{ 
	vuln_func();
	return 0; 
}
