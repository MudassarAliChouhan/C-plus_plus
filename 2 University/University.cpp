#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<stdio.h>
#include<ctime>
#include<cstdlib>
#include<string.h>
#include<windows.h>

using namespace std;

#include "UniFun.h"
#include "output.c"
#include "Subject.c"
#include "collage.cpp"
#include "idintity.cpp"
#include "student.cpp"

int main()
{
	select(30,38,5);
	
	exit(0);
	
	
	while(1)
	{
		system("cls");
		switch(main_m())
		{
			case 49:
				studentMenu();
				break;
			case 50:
				collageMenu();
				break;
			case 'e':
				exit(0);
				break;
		}
	}
	
	//getch();
}