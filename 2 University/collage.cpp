	/// Set Functions :)
int collage::setSubj(char *sub,int num)
{
	if(num>=0&&num<20)
	{
		strcpy(subjects[num],sub);
		return 1;
	}
	return 0;
}
int collage::setDegree(char *deg,int num)
{
	if(num>=0&&num<20)
	{
		strcpy(degrees[num],deg);
		return 1;
	}
	return 0;
}

	/// Get Functions :)
char* collage::getSubj(int idx)
{
	char sub[30];
	strcpy(sub,subjects[idx]);
	return sub;
}
char* collage::getDegree(int idx)
{
	char deg[7];
	strcpy(deg,degrees[idx]);
	return deg;	
}

/// Utitlity

void viewColge(collage c)
{
	cout<<"\n\n ID# "		<<c.getId()<<endl;
	cout<<"\n Name: "		<<c.getName();
	cout<<"\n Contect: "	<<c.getContect();
	cout<<"\n Address: "	<<c.getAddr();
	cout<<"\n Degrees: "	;
}
void listStudColge()
{
	
}
char* getSubj()
{
	int y = 5;
	//char *subj,*deg;
	struct subject sub;
	ifstream fin;
	fin.open(SUBJECT_FILE,ios::in);
	if(!fin.eof())
	{
		cout<<"\n File not Exist";
		return 0;
	}
	while(!fin.eof())
	{		
		fin.read((char*)&sub,sizeof(sub));
		gotoxy(40,y++);
		cout<<sub.subj<<" | "<<sub.degree;
	}
	select(30,38,5);
}
void addColge(collage *colge)
{
	char ch[30];
	int count=0;
	
	colge->setId();
	cout<<"\n\n ID: "<<colge->getId();
	
	cout<<"\n Name: ";
	cin.getline(ch,25);
	colge->setName(ch);
	
	cout<<"\n Contect#: ";
	cin.getline(ch,12);
	colge->setContect(ch);
	
	cout<<"\n Address: ";
	cin.getline(ch,30);
	colge->setAddr(ch);
	
	cout<<"\n Seclect Subjects: ";
	do{
		getSubj();
		
	}while(getch()!=27);
}
int addColgeRec()
{
	collage c;
	addColge(&c);
	if(confermbox("Do you want to Save"))
	{
		ofstream fout;
		fout.open(COLLAGE_FILE,ios::app);
		if(!fout)
		{
			cout<<"\n File Creating ERROR";
			return 0;
		}
		fout.write((char*)&c,sizeof(c));
		fout.close();
		cout<< "\n Your Record is successfully stored";
	}
	return 1;
}
int viewAllColge()
{
	collage c;
	ifstream fin;
	fin.open(COLLAGE_FILE,ios::in);
	if(!fin)
	{
		cout<<"\n File not exist";
		return 0;
	}
	while(!fin.eof())
	{
		viewColge(c);
		fin.read((char*)&c,sizeof(c));
	}
	fin.close();
	return 1;
}
int dellColge()
{
	int id;
	collage c;
	fstream fin,fout;
	
	fin.open(COLLAGE_FILE,ios::in);
	fout.open(COLLAGE_TMP,ios::out);
	if(!fout)
	{
		cout<<"\n File Creating ERROR";
		return 0;
	}
	if(!fin)
	{
		cout<<"\n File not exist";
		fout.close();
		remove(COLLAGE_TMP);
		return 0;
	}
	
	cout<< "Enter ID: ";
	cin>>id;
	
	while(!fin.eof())
	{
		if(id!=c.getId())
			fout.write((char*)&c,sizeof(c));
		fin.read((char*)&c,sizeof(c));
	}
	fin.close();
	fout.close();

	remove(COLLAGE_FILE);
	rename(COLLAGE_TMP,COLLAGE_FILE);
	return 1;
}
int searchColge()
{
	int id;
	collage c;
	ifstream fin;
	
	fin.open(COLLAGE_FILE,ios::in);
	if(!fin)
	{
		cout<<"\n File not exist";
		return 0;
	}
	
	cout<<"Enter Collage ID: ";
	cin>>id;	
		
	while(!fin.eof())
	{
		if(id==c.getId())
			viewColge(c);
		fin.read((char*)&c,sizeof(c));
	}
	fin.close();
}
int editColge()
{
	
	int id;
	collage c;
	
	fstream file;
	file.open(COLLAGE_FILE,ios::in|ios::ate);
	if(!file)
	{
		cout<<"\n File Opration not Ferfomed";
		return 0;
	}
	
	cout<<"Enter Collage ID: ";
	cin>>id;
	
	while(!file.eof())
	{
		if(id==c.getId())
		{
			viewColge(c);	getch();
			system("cls");
			addColge(&c);
			file.seekp(file.tellg()-sizeof(c));
			file.write((char*)&c,sizeof(c));
		}
		file.read((char*)&c,sizeof(c));
	}
	file.close();
}
void collageMenu()
{
	system("cls");
	print(
	Collage,sizeof(Collage)/sizeof(*Collage));
	switch(getch())
	{
		case '1':system("cls");
			title("Inserting a new Record");
			addColgeRec();
			break;
		case '2':system("cls");
			title("Deliting a Record");
			dellColge();
			break;
		case '3':system("cls");
			title("Modification");
			editColge();
			break;
		case '4':system("cls");
			title("Display Records are listed");
			viewAllColge();
			break;
		case '5':system("cls");
			title("Search a Record");
			searchColge();
			break;	
	}
	getch();
}
