#include "Behaviour.cpp"
#include "Utitlity.cpp"
void collageMenu()
{
	system("cls");
	title("Collage Managements");
	print(Collage,sizeof(Collage)/sizeof(*Collage));
	switch(select(sizeof(Collage)/sizeof(*Collage),6,8,2))
	{
		case 1:system("cls");
			title("Inserting a new Record");
			addColgeRec();
			break;
		case 2:system("cls");
			title("Deliting a Record");
			dellColge();
			break;
		case 3:system("cls");
			title("Modification");
			editColge();
			break;
		case 4:system("cls");
			title("Display Records are listed");
			viewAllColge();
			break;
		case 5:system("cls");
			title("Search a Record");
			searchColge();
			break;	
	}
	getch();
}
