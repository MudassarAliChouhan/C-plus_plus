
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
void addColge(collage *colge)
{
	char ch[30];
	int i=1;
	
	colge->setId();
	cout<<"\n\n ID: "<<colge->getId();
	
	fflush(stdin);
	
	cout<<"\n Name: "; 
	cin.getline(ch,25);
	strupr(ch);
	colge->setName(ch);
	
	cout<<"\n Contect#: ";
	cin.getline(ch,12);
	colge->setContect(ch);
	
	cout<<"\n Address: ";
	cin.getline(ch,30);
	colge->setAddr(ch);
	
	cout<<"\n Seclect Subjects: ";
	
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
		cout<<"\n File reserved";
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
			title("Updating...");
			addColge(&c);
			file.seekp(file.tellg()-sizeof(c));
			file.write((char*)&c,sizeof(c));
			file.close();
			cout<<"\n\n \tUpdate recored!!!";
			return 1;
		}
		file.read((char*)&c,sizeof(c));
	}
	file.close();
	return 0;
}
