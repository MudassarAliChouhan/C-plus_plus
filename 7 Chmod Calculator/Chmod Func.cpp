/*

    All Function are define here

*/

inline int chmod::exist(int est)
{
    if(est>0 && est<=9)
        if(noperm[est-1] == 1)
            return 1;
    return 0;
}
void chmod::display()
{
    char cheack = 251;
    for(int index=0; index<9; index++)
    {
        if(exist(index+1) == 1)
        {
            gotoxy(posxy[index].x+1 , posxy[index].y);
            cout<<cheack;
            continue;
        }
        gotoxy(posxy[index].x+1 , posxy[index].y);
        cout<<"X";
    }
}
inline void chmod::unchk(int unck)
{
    if(unck>0 && unck<=9)
        noperm[unck-1] = 0;
}
inline void chmod::chk(int ck)
{
    if(ck>0 && ck<=9)
        noperm[ck-1] = 1;
}
void chmod::command()
{
    string str;
    cout<<"chmod +";
    int permit=0,chk=0,tmp;

    for(int tmp=1; tmp<=3; tmp++,chk++)
    {
        if(exist(tmp))
            permit += permitStak[chk];
    }
    cout<<permit;

    permit = 0;chk = 0;
    for(tmp=4; tmp<=6; tmp++,chk++)
    {
        if(exist(tmp))
            permit += permitStak[chk];
    }
    cout<<permit;

    permit = 0;chk = 0;
    for(tmp=7; tmp<=9; tmp++,chk++)
    {
        if(exist(tmp))
            permit += permitStak[chk];
    }
    cout<<permit;
    cout<<" File_Name";
}
void chmod::menu(int ftsize)
{
    if(ftsize>13)
        ftsize =13;
    int incre;

    gotoxy(ftsize,ftsize);
    setColor(2);

    incre=ftsize;
    for(int tmp=0; tmp<3; tmp++)
    {
        gotoxy(incre,wherey()-1);
        cout<<list[tmp];
        gotoxy(incre,wherey()+1);
        cout<<"-----------";
        incre+=ftsize+15;
    }

    setColor(5);

    incre=ftsize;
    for(int tmp=0,index=0; tmp<3; tmp++)
    {
        gotoxy(incre,wherey()+2);
        cout<<perm[0];
        posxy[index].x=wherex();
        posxy[index++].y=wherey();

        gotoxy(incre,wherey()+2);
        cout<<perm[1];
        posxy[index].x=wherex();
        posxy[index++].y=wherey();

        gotoxy(incre,wherey()+2);
        cout<<perm[2];
        posxy[index].x=wherex();
        posxy[index++].y=wherey();

        incre+=ftsize+15;
        gotoxy(incre,wherey()-6);
    }

    setColor(15);
}
inline void chmod::gotoxy(int column,int row)
{
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
inline int chmod::wherex()
{
    (GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE),&csbi));
      return csbi.dwCursorPosition.X;
}
inline int chmod::wherey()
{
    (GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi));
      return csbi.dwCursorPosition.Y;
}
inline void chmod::setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
