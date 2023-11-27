#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char string[5];
    strcpy(string, argv[1]);
    printf("%s\n", string);
    return 0;
}
