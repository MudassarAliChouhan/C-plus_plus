#include "Subject.c"
subjectMenu()
{
	system("cls");
	title("Subject Management");
	print(Subject,sizeof(Subject)/sizeof(*Subject));
	switch(select(sizeof(Subject)/sizeof(*Subject),6,8,2))
	{
		case 1:system("cls");
			title("Inserting...");
			insert();
			break;
		case 2:system("cls");
			title("Display...");
			display();
			getch();
			break;
	}
}
