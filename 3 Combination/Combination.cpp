#include<iostream>
#include<string>

using namespace std;

void swap(string &a,string &b)
{
    string ch;
    ch = a;
    a = b;
    b = ch;
}
int endf(int size)
{
    int n = size;
    for(int i=1; i<size; i++)
    {
        n = n * i;
    }
    return n;
/*
    1 = 1
    2 = 2
    3 = 6
    4 = 24
    5 = 120
    7 = 720
    ....
*/
}
void combination(string str)
{
    int len = str.length(); // Lenth of given String
    int end = endf(len);    // End of the 2th_Loop
    int *swapOver = new int[len];
    string *cp = new string[end+1];

    swapOver[0] = end/len;
    for(int i=1;i<len;i++)
    swapOver[i] = swapOver[i-1]/(len-i);

    for(int j=0; j<end; j++)
            cp[j]=str;

    for(int round=0,j,k; round < len; round++)
    {
        j=0; k=round;

        for(j; j<end; j++)
        {
            if(j%swapOver[round] == 0)
                swap(cp[j][round], cp[j][k++]);
            else
            {
                swap(cp[j][round], cp[j][k]);
            }

            if(k>len-1)
                k=round;
        }
    }
    for(int j=0; j<end; j++)
            cout <<cp[j]<<endl;
    delete [] cp;
    delete [] swapOver;
}
int main()
{
    combination("abcdefghi");
    return 1;
}
