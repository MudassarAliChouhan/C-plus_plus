

#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
#include<stdio.h>

#define up 72
#define down 80
#define left 75
#define right 77

using std::string;
using std::cin;
using std::endl;
using std::cout;

class chmod
{
private:

    struct xy
    {
        int x;
        int y;
    };
    string list[3];
    string perm[3];
    int noperm[9];
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord;


    void menu(int);
    int wherex(void);
    int wherey(void);
    void setColor(int);

public:


    struct xy posxy[9];

    void gotoxy(int, int);
    void unchk(int);
    void chk(int);
    void display(void);
    int exist(int);
    int permitStak[3];
    void command(void);
    //string command();

    chmod(int ftsize)
    {
        list[0] = "OWN";
        list[1] = "GROUP";
        list[2] = "PUBLIC";

        perm[0] = "Read";
        perm[1] = "Write";
        perm[2] = "Execute";

        permitStak[0] = 1;
        permitStak[1] = 2;
        permitStak[2] = 4;

        menu(ftsize);
        gotoxy(posxy[0].x,posxy[0].y);
    }
};
