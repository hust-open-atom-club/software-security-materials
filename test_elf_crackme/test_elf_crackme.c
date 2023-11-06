#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

int main()
{
	int result, input;
       
	printf("3 + 5 = ?\n");
	input = getchar();
	if (input == EOF) return -EINVAL;

	if (input >= '0' && input <= '9') {
		result = input - '0';
	} else {
		printf("Not an integer\n");
	}

	if (result == 8) {
		printf("The answer is correct\n");
	} else {
		printf("The answer is incorrect\n");
	}

	return 0;
}
