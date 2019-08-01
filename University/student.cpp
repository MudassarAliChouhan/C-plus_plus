
	/// Set Functions :)

void student::setStream(char *s)
{
	strcpy(stream , s);
}
void student::setDegree(char *d)
{
	strcpy(degree , d);
}
void student::setFName(char *n)
{
	strcpy(fName , n);
}
void student::setFee(int f)
{
	fee = f;
}
void student::setFine(int f)
{
	fine = f;
}
void student::setColge(char *c)
{
	strcpy(colge , c);
}
void student::setOptSub(char *sub,int i)
{
	i-1;
	if(i>0 && i<4)
	{
		strcpy(optSub[i],sub);
	}
}

	/// Get Functions :)
char* student::getFName()
{
	return fName;
}
int student::getFee()
{
	return fee;
}
int student::getFine()
{
	return fine;
}
char* student::getColge()
{
	return colge;
}
char* student::getCompSub(int i)
{
	char sub[30];
	i-1;
	if(i>0 && i<4)
		strcpy(sub, compSub[i]);
	return sub;
}
char* student::getOptSub(int i)
{
	char c[30];
	i-1;
	if(i>0 && i<4)
	{
		strcpy(c,optSub[i]);		
	}
	return c; 
}
char* student::getStream()
{
	return stream;
}
char* student::getDegree()
{
	return degree;
}

// Utility
void viewStud(student s)
{
	cout<<"\n\n ID# "<<s.getId()<<endl;
	cout<<"\n Collage: --- "<<s.getColge();
	cout<<"\n Name: ------ "<<s.getName();
	cout<<"\n Father Name: "<<s.getFName();
	cout<<"\n Contect#: -- "<<s.getContect();
	cout<<"\n Address: --- "<<s.getAddr();
	cout<<"\n Stream: ---- "<<s.getStream();
	cout<<"\n Degree: ---- "<<s.getDegree();
	cout<<"\n Fee: ------- "<<s.getFee();
	cout<<"\n Fine: ------ "<<s.getFine();
	cout<<"\n Subjects: -- "<<s.getCompSub(1);
	cout<<"\n \t\t"<<s.getCompSub(2);
	cout<<"\n \t\t"<<s.getCompSub(3);
	cout<<"\n \t\t"<<s.getOptSub(1);
	cout<<"\n \t\t"<<s.getOptSub(2);
	cout<<"\n \t\t"<<s.getOptSub(3);
}
void addStud(student *stud,int id)
{
	char ch[30];
	int num;
	
	cout<<"\n\n\n\t ID: "<<stud->getId()<<endl;
	cout<< "\n\t Enter Collage Name: ";
	cin.getline(ch,20);
	stud->setColge(ch);
	cout<< "\n\t Enter Name: ";
	cin.getline(ch,25);
	stud->setName(ch);
	cout<<"\n\t Father Name: ";
	cin.getline(ch,25);
	stud->setFName(ch);
	cout<<"\n\t Contect#: ";
	cin.getline(ch,12);
	stud->setContect(ch);
	cout<<"\n\t Address: ";
	cin.getline(ch,30);
	stud->setAddr(ch);
	cout<<"\n\t Stream: ";
	cin.getline(ch,10);
	stud->setStream(ch);
	cout<<"\n\t Degree: ";
	cin.getline(ch,6);
	stud->setDegree(ch);
	cout<<"\n\t Fee: ";
	cin>>num;
	stud->setFee(num);
	cout<<"\n\t Fine: ";
	num=0;
	cin>>num;
	stud->setFine(num);
	cin.ignore();
	cout<<"\n Enter Subjects: ";
	cout<<"\t\t 1- ";cin.getline(ch,30);
	stud->setOptSub(ch,1);
	cout<<"\t\t 2- ";cin.getline(ch,30);
	stud->setOptSub(ch,2);
	cout<<"\t\t 3- ";cin.getline(ch,30);
	stud->setOptSub(ch,3);
}
int addStudRec()
{
	student s;	
	addStud(&s,s.setId());
		
	if(confermbox("Do you want to Save"))
	{
		ofstream fout;
		fout.open(STUDENT_FILE,ios::app);
		if(!fout)
		{
			cout<< "\n File Creating ERROR";
			getch();
			//Sleep(900);
			return 0;
		}
		fout.write((char*)&s,sizeof(s));
		fout.close();
		cout<< "\n Your Record is successfully stored";
	}
}
int viewAllStud()
{
	ifstream fin;
	student s;
	fin.open(STUDENT_FILE,ios::in);
	if(!fin)
	{
		cout<< "\n File not eixt";
		getch();
		//Sleep(900);
		return 0;
	}
	fin.read((char*)&s, sizeof(s));
	while(!fin.eof())
	{
		viewStud(s);
		fin.read((char*)&s, sizeof(s));
	}
	fin.close();
	return 1;
}
int dellStud()
{
	int id;
	
	student s;
	
	ifstream fin;
	ofstream fout;
	
	cout<< "\n Sudent ID: ";
	cin>>id;
	
	fin.open(STUDENT_FILE,ios::in);
	if(!fin)
	{
		cout<< "\n File not eixt";
		getch();
		//Sleep(900);
		return 0;
	}
	fout.open(STUDENT_TMP,ios::out);
	
	fin.read((char*)&s,sizeof(s));
	while(!fin.eof())
	{
		if(s.getId()!=id)
			fout.write((char*)&s,sizeof(s));
			
		fin.read((char*)&s,sizeof(s));
	}
	
	fin.close();
	fout.close();
	
	remove(STUDENT_FILE);
	rename(STUDENT_TMP,STUDENT_FILE);
	cout<<"\n Done!!!";
}
int searchStud()
{
	int id;
	student s;
	ifstream fin;
	fin.open(STUDENT_FILE,ios::in);
	if(!fin)
	{
		cout<< "\n File not eixt";
		getch();
		//Sleep(900);
		return 0;
	}	
	cout<< "\n Sudent ID: ";
	cin>>id;
	fin.read((char*)&s,sizeof(s));
	while(!fin.eof())
	{
		if(s.getId()==id)
			viewStud(s);
		fin.read((char*)&s,sizeof(s));
	}
	fin.close();
}
int editStud()
{
	int id;
	cout<<"\n Enter ID: ";
	cin>>id;
	fstream file;
	student s;
	file.open(STUDENT_FILE,ios::ate|ios::in);
	file.seekp(0);
	file.read((char*)&s,sizeof(s));
	if(!file)
	{
		cout<< "\n File not eixt";
		getch();
		//Sleep(900);
		return 0;
	}
	while(!file.eof())
	{
		if(s.getId()==id)
		{
			cout<<"I find This "<<s.getId()<<endl;
			viewStud(s);
			getch();
			file.seekp(file.tellg()-sizeof(s));
			addStud(&s,s.getId());
			file.write((char*)&s,sizeof(s));
		}
		file.read((char*)&s,sizeof(s));
	}
}
void studentMenu()
{
	system("cls");
	print(Student,sizeof(Student)/sizeof(*Student));
	switch(getch())
	{
		fflush(stdin);
		case '1':system("cls");
			title("Addition of Student Record's");
			addStudRec();
			break;
		case '2':system("cls");
			title("Delliting a Record");
			dellStud();
			break;
		case '3':system("cls");
			title("Modification");
			editStud();
			break;
		case '4':system("cls");
			title("Display Records are listed");
			viewAllStud();
			break;
		case '5':system("cls");
			title("Search a Record");
			searchStud();
			break;	
	}
	getch();
}

