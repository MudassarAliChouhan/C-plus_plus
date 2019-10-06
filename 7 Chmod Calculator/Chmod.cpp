#include"Chmod.hpp"
#include"Chmod Func.cpp"

int main()
{
    chmod cmd(7);
    char choice;
    int locate=1;
    int i=0;

    while(1)
    {
        fflush(stdin);
        choice = getch();

        switch(choice)
        {


        case up:
            --locate;   break;
        case down:
            ++locate;   break;
        case left:
            locate-=3;  break;
        case right:
            locate+=3;  break;
        case ' ':
            if(cmd.exist(locate)==1)
                cmd.unchk(locate);
            else if(cmd.exist(locate)!=1)
                cmd.chk(locate);
            break;
        case 13:
            cmd.gotoxy(25,cmd.posxy[8].y+3);
            cmd.command();
            break;
        }
        if(locate<=1)
            locate = 1;
        else if(locate>=9)
            locate = 9;
        cmd.display();
        cmd.gotoxy(cmd.posxy[locate-1].x,cmd.posxy[locate-1].y);

    }
    return 1;
}
