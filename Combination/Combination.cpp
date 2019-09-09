#include<iostream>
#include<string.h>

using namespace std;

void swap(char &a,char &b)
{
    char ch;
    ch = a;
    a = b;
    b = ch;
}
int endf(int size)
{
    int n = size;
    for(int i=1; i<size; i++)
        n = n * i;
    return n;
}
void combination(char *str)
{
    int len = strlen(str);
    int end = endf(len);
    int swapOver = end/len;
    char *cp = new char[len];

    strcpy(cp , str);

    for(int i=0 ,j=0; i < end; i++)
    {
        cout << cp << endl;
        if( (i+1) % swapOver == 0)
        {
            j++;
            swap(cp[0],cp[j]);
        }
        if( (i+1) % swapOver == 0)
        {
            j++;
            swap(cp[0],cp[j]);
        }
    }
}
int main()
{
    combination("123456");
    return 1;
}
