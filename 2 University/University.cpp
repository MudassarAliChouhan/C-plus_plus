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

#include "University.h"

int main()
{
	while(1)
	{
		system("cls");
		title(" Main Page ");
		switch(main_m())
		{
			case 1:
				studentMenu();
				break;
			case 2:
				collageMenu();
				break;
			case 5:
				subjectMenu();
				break;
			case 6:system("cls");
				title(" Good Bye... ");
				puts("\n\n\tThank You for using our Software.");
				Sleep(1000);
				exit(0);
				break;
		}
	}
}
