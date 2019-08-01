#define SUBJECT_FILE "Subjects.dat"
struct subject
{
	char subj[30];
	char degree[7];
};
void display()
{
	FILE *fptr;
	struct subject sub;

	fptr = fopen(SUBJECT_FILE,"rb+");
			if(!fptr)
			{
				puts("\n File not exit!!!");
				Sleep(3000);
				exit(0);
			}
			while(!feof(fptr))
			{
				fread(&sub,sizeof(sub),1,fptr);
				printf("\n %s | %s",sub.subj,sub.degree);
			}
	fclose(fptr);
}
void insert()
{
	FILE *fptr;
	struct subject sub;
	fptr = fopen(SUBJECT_FILE,"ab");
	
			if(!fptr)
			{
				puts("\n File Creating:ERROR!!!");
				Sleep(3000);
				exit(0);
			}
			while(1)
			{
				
				printf("\n Press -Esc- for exit: ");
				if(getch()==27)
			 		break;
				printf("\n Enter New Subject: ");
				gets(sub.subj);
				printf("\n Mention Degree: ");
				gets(sub.degree);
				if(confermbox("Do you want to Save"))
				{
					fwrite(&sub,sizeof(sub),1,fptr);
				}
			}
	fclose(fptr);
		
}
