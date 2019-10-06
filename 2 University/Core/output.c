void gotoxy(int , int);
#define DOWN 80
#define UP 72
#define ABC1
#define NUM 2
#define ABC123 3
#define EMAIL 4
char* get(char *str, int pst,int size)
{
	
		char ch;
		int i=0;
	switch(pst)
	{
		case 1:
			do
			{
				ch = getch();
				if(('a'<=ch && 'z'>=ch)||('A'<=ch && 'Z'>=ch))
				{
					str[i++]=ch;
					printf("%c",ch);
				}
				if(ch==8)
				{
					i--;
				}
			}while(ch!=13);
			str[i]='\0';
			return str;
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
	}
}
int select(int max,int x,int y,int step)
{
	int chose=0, value=1;
	//int min = y;
	do
	{
		switch(chose)
		{
			case DOWN:
				if(value < max)
				{
					y+=step; value++;
				}
				break;
			case UP:
				if(value > 1)
				{
					y-=step; value--;
				}
				break;
		}
		gotoxy(x,y);
		printf("->");
		gotoxy(0,0);
		chose=getch();
		gotoxy(x,y);
		printf("  ");
	}while(chose!=13);
	
	return value;
}
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
		"Exams System",
		"Result's",
		"Subject Managements",
		"EXIT"
	};

opt Student[] =
	{
		"Add Some One",
		"A Dell",
		"Edit such as",
		"View All",
		"Search Particular",
		"Back"
	};

opt Collage [] =
{
	"Add Some One",
	"A Dell",
	"Edit such as",
	"View All",
	"Search Particular",
	"View All Student",
	"Back"
};

opt Subject [] =
{
	"Insertion",
	"Display",
	"Back"
};

int print(opt *o,int i)
{
	int j = 1;
	printf("\n\n\n\n");
	while(j<=i)
	{
		printf("\n\t %s\n" ,o[j-1]);
		j++;
	}
	return j;
}
int main_m()
{
	print(aWel,sizeof(aWel)/sizeof(*aWel));
	return(select(sizeof(aWel)/sizeof(*aWel),6,8,2));
}
