#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

int main()
{
	bool match = false;
	int result;
	char buffer[8];
       
	printf("3 + 5 = ?\n");
	scanf("%s", buffer); // vulnerable scanf
	result = atoi(buffer);

	if (result == 3+5) match = true;

	if (match) {
		printf("The answer is correct\n");
	} else {
		printf("The answer is incorrect\n");
	}

	return 0;
}
