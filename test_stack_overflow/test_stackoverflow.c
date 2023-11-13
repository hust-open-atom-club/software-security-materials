#include <string.h>
#include <stdio.h>

int BFunc (int i, int j)
{
    int m = 1;
    int n = 2;
    char szBuf[8] = {0};

    m = i;
    n = j;

    printf("m = 0x%x n = 0x%x\n", m, n);

    strcpy(szBuf, "stack overflow!");

    printf("m = 0x%x n = 0x%x\n", m, n);
    return m;
}


int AFunc(int i,int j)
{
    int m = 3;
    int n = 4;
    m = i;
    n = j;
    BFunc(m,n);
    return 8;
}


int main()
{
    AFunc(5,6);
    return 0;
}

