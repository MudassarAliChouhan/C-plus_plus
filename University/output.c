void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
typedef char opt[20];
/*

	Student	-> Add, dell, edit, Search
	Collage	-> Add, dell, edit, Search, list student's 
	Exam	-> Enter masks
	Result	-> view, annnouce date

*/
int confermbox(char *ch)
{
	cout<<"\n "<<ch<<" ('y' / 'n') ";
	char c = getch();
	if(c=='y'||c=='y')
		return 1;
	return 0;
}

void title(char *ch)
{
	int i;
	printf("\n\t\t");
	for(i=0;i<=strlen(ch);i++)
	{
		printf("^");
	}
	
	printf("\n\t\t %s",ch);
	
	printf("\n\t\t");
	for(i=0;i<=strlen(ch);i++)
	{
		printf(".");
	}
}

opt aWel[] =
	{
		"Student",
		"Collage",
		"Exam",
		"Result",
		"Name",
		"exit"
	};

opt Student[] =
	{
		"Add Some One",
		"A Dell",
		"Edit such as",
		"View All",
		"Search Particular"
	};

opt Collage [] =
{
	"Add Some One",
	"A Dell",
	"Edit such as",
	"View All",
	"Search Particular",
	"View All Student"
};

int print(opt *o,int i)
{
	int j = 1;
	printf("\n\n\n\n\n\n\n\n");
	while(j<=i)
	{
		printf("\n\t\t %d. %s\n" ,j, o[j-1]);
		j++;
	}
	return j;
}

int main_m()
{
	print(aWel,sizeof(aWel)/sizeof(*aWel));
	return(getch());
}
