#include "Behaviour.cpp"
#include "Utitlity.cpp"
void studentMenu()
{
	system("cls");
	title("Student Managements");
	
	print(Student,sizeof(Student)/sizeof(*Student));
	switch(select(sizeof(Student)/sizeof(*Student),6,8,2))
	{
		fflush(stdin);
		case 1:system("cls");
			title("Addition of Student Record's");
			addStudRec();
			break;
		case 2:system("cls");
			title("Delliting a Record");
			dellStud();
			break;
		case 3:system("cls");
			title("Modification");
			editStud();
			break;
		case 4:system("cls");
			title("Display Records are listed");
			viewAllStud();
			break;
		case 5:system("cls");
			title("Search a Record");
			searchStud();
			break;	
	}
	getch();
}

