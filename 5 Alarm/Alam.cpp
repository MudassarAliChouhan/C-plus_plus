#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define SEC 1000
#define up 72
#define down 80
#define right 67
#define left 68
#pragma comment(lib, "winmm.lib")

using namespace std;

void gotoxy(int column,int row)
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE),&csbi))
    return -1;
  return csbi.dwCursorPosition.X;
  }
int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi))
    return -1;
  return csbi.dwCursorPosition.Y;
  }
int integer(char s='t')
{
    int i=0;
    int x=wherex(),y=wherey();
    if(s=='h')
    {
        char chk;
            do
            {
                gotoxy(x,y);
                cout<<i<<" ";
                chk=getch();
                if(chk==up)
                    i++;
                if(chk==down)
                    i--;
                if(i<0||i>23)
                    i=0;
            }while(chk!=13);
            return i;
    }
    char chk;
        do
        {
            gotoxy(x,y);
            cout<<i<<" ";
            chk=getch();
            if(chk==up)
                i++;
            if(chk==down)
                i--;
            if(i<1||i>60)
                i=1;
        }while(chk!=13);
        return i;
}
int main()
{
    int min,hour;
    cout<< "Set Time hh/mm (24 Formate) \n\t ";
    hour=integer('h');
    cout<<" ";
    min=integer();
    while(1)
    {
    time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        if(tm.tm_hour==hour&&min==tm.tm_min)
            break;
        gotoxy(5,wherey());cout<<"Time is "<<tm.tm_hour<<":"<<tm.tm_min<<":"<<tm.tm_sec;
        Sleep(SEC);
    }
    system("start Chal_Oye.mp3");
    return 1;
}
