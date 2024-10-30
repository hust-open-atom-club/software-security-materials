int BFunc (int i, int j) {
    int m = 1;
    int n = 2;
    m = i;
    n = j;
    return m;
}

int AFunc(int i,int j) {  int m = 3;  int n = 4;
    m = i;  n = j;
    BFunc(m,n);
    return 8;
}


int main()
{
    AFunc(5, 6);
    return 0;
}

