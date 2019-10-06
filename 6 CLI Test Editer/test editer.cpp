#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class TextEditer
{

public:
    int write(string,char*);
};

int TextEditer::write(string str,char *filename)
{
    ofstream fout;
    fout.open(filename,ios::out);

    fout.get(str);

    fout.close();

    return 1;
}

int main()
{
    TextEditer obj;

    string fileInput;
    cin>>fileInput;
    obj.write(fileInput,"new.txt");


}
