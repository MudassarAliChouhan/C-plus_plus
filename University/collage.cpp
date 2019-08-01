
/// Utitlity

void viewColge(collage c)
{
	cout<<"\n\n ID: "		<<c.getId()<<endl;
	cout<<"\n Name: "		<<c.getName();
	cout<<"\n Contect#: "	<<c.getContect();
	cout<<"\n Address: "	<<c.getAddr();
}

void addColge(collage *colge)
{
	char ch[30];
	
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
}
int addColgeRec()
{
	collage c;
	addColge(&c);
	if(confermbox("Do you want to Save"))
	{
		ofstream fout;
		fout.open(COLLAGE_FILE,ios::app);
		fout.write((char*)&c,sizeof(c));
		fout.close();
		cout<< "\n Your Record is successfully stored";
	}
}
int viewAllColge()
{
	collage c;
	ifstream fin;
	fin.open(COLLAGE_FILE,ios::in);
	while(!fin.eof())
	{
		viewColge(c);
		fin.read((char*)&c,sizeof(c));
	}
	fin.close();
}
int dellColge()
{
	int id;
	cout<< "Enter ID: ";
	cin>>id;
	collage c;
	fstream fin,fout;
	fin.open(COLLAGE_FILE,ios::in);
	fout.open(COLLAGE_TMP,ios::out);
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
}
int searchColge()
{
	int id;
	collage c;
	
	cout<<"Enter Collage ID: ";
	cin>>id;
	
	ifstream fin;
	fin.open(COLLAGE_FILE,ios::in);
	
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
	
	cout<<"Enter Collage ID: ";
	cin>>id;
	
	fstream file;
	file.open(COLLAGE_FILE,ios::in|ios::ate);
	
	while(!file.eof())
	{
		if(id==c.getId())
		{
			viewColge(c);
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
