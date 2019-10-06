#define SUBJECT_FILE "Data/Subjects.dat"
struct subject
{
	char subj[30];
	char degree[7];
};
int display()
{
	FILE *fptr;
	struct subject sub;
	int y=7;

	fptr = fopen(SUBJECT_FILE,"rb+");
			if(!fptr)
			{
				puts("\n File not exit!!!");
				Sleep(3000);
				return 0;
			}
			puts("\n\n\t\t List existing Records.\n\n");
			while(!feof(fptr))
			{
				fread(&sub,sizeof(sub),1,fptr);
				gotoxy(3,y); 	printf("%s",sub.subj);
				gotoxy(35,y++);	printf("| %s",sub.degree);
			}
	fclose(fptr);
}
int insert()
{
	FILE *fptr;
	struct subject sub;
	fptr = fopen(SUBJECT_FILE,"ab");
	
			if(!fptr)
			{
				puts("\n File Creating:ERROR!!!");
				Sleep(3000);
				return 0;
			}
			printf("\n\n\t Press -Esc- for exit: ");
			while(1)
			{
				printf("\n Enter New Subject: ");
				gets(sub.subj);
				printf("\n Mention Degree: ");
				gets(sub.degree);
				if(confermbox("Do you want to Save"))
				{
					fwrite(&sub,sizeof(sub),1,fptr);
				}
				puts("\nDo you want Add another data");
				if(getch()==27)
			 		break;
				puts(" ---------------------------------");
			}
	fclose(fptr);		
}
