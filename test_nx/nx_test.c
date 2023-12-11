// 1.c
#include<stdio.h>
void func()
{
    char name[0x50];//0x100大小的栈空间
    read(0, name, 0x100);//输入0x200大小的数据
    write(1, name, 0x100);
}
int main()
{
    func();
    return 0;
}
