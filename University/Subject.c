#include<stdio.h>
#define SUBJECT_FILE "Subjects.dat"
struct subject
{
	char subj[30];
	char degree[6];
}
main()
{
	FILE *fptr;
	struct subject sub;
	printf("Press: 'v' for View -OR- 'i' for Insert");
	switch(getch())
	{
		case 'v':
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
			close(fptr);
		break;
		
		case 'i':
			fptr = fopen(SUBJECT_FILE,"ab");
			if(!fptr)
			{
				puts("\n File Creating:ERROR!!!");
				Sleep(3000);
				exit(0);
			}
			puts("\n Press: -Esc- for DONE:)");
			while(1)
			{
				printf("\n Enter New Subject: ");
				gets(sub.subj);
				printf("\n Mention Degree: ");
				gets(sub.degree);
				fwrite(&sub,sizeof(sub),1,fptr);
				if(getch()==27)
			 		break;
			}
			close(fptr);
		break;
		
	}
}
