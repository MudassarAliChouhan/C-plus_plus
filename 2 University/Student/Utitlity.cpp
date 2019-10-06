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
	fflush(stdin);
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
	cout<<"\n Enter Subjects:\n";
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
			Sleep(SEC);
			return 0;
		}
		fout.write((char*)&s,sizeof(s));
		fout.close();
		cout<< "\n Your Record is successfully stored";
	}
	cout<< "\n Your Record Can't be stored";
}
int viewAllStud()
{
	ifstream fin;
	student s;
	int count=0;
	
	fin.open(STUDENT_FILE,ios::in);
	if(!fin)
	{
		cout<< "\n File not eixt";
		Sleep(SEC);
		return 0;
	}
	fin.read((char*)&s, sizeof(s));
	while(!fin.eof())
	{
		viewStud(s);
		fin.read((char*)&s, sizeof(s));
		count=1;
	}
	fin.close();
	
	if(count==0)
		cout<< "\n\n \t You can't be Store any Recored!!!";
	return 1;
}
int dellStud()
{
	int id,chk=0;	
	student s;
	
	ifstream fin;
	ofstream fout;
		
	fin.open(STUDENT_FILE,ios::in);
	if(!fin)
	{
		cout<< "\n File not eixt";
		Sleep(SEC);
		return 0;
	}
	
	cout<< "\n Sudent ID: ";
	cin>>id;
	
	fout.open(STUDENT_TMP,ios::out);
	
	fin.read((char*)&s,sizeof(s));
	while(!fin.eof())
	{
		if(s.getId()!=id)
			fout.write((char*)&s,sizeof(s));
		else
		{
			viewStud(s);
			chk=1;
		}
		fin.read((char*)&s,sizeof(s));
	}
	
	fin.close();
	fout.close();
	
	remove(STUDENT_FILE);
	rename(STUDENT_TMP,STUDENT_FILE);
	
	if(chk)
		cout<<"\n\n \t Done!!!";
	else 
	{
		cout<< "\n\n \t Record not Found!!!";
		return 0;
	}
	return 1;
}
int searchStud()
{
	int id,chk=0;;
	student s;
	ifstream fin;
	
	fin.open(STUDENT_FILE,ios::in);
	if(!fin)
	{
		cout<< "\n File not eixt";
		Sleep(900);
		return 0;
	}
	
	cout<< "\n Sudent ID: ";
	cin>>id;
	
	fin.read((char*)&s,sizeof(s));
	while(!fin.eof())
	{
		if(s.getId()==id)
		{
			viewStud(s);
			chk=1;
		}
		fin.read((char*)&s,sizeof(s));
	}
	fin.close();
	
	if(chk==0)
	{
		cout<<"\n\n \t Record not Found!!!";
		return 0;
	}
	
	return 1;
}
int editStud()
{
	int id;
	fstream file;
	student s;
	
	file.open(STUDENT_FILE,ios::ate|ios::in);
	file.seekp(0);
	file.read((char*)&s,sizeof(s));
	if(!file)
	{
		cout<< "\n File not eixt";
		Sleep(900);
		return 0;
	}
	
	cout<<"\n Enter ID: ";
	cin>>id;
	
	while(!file.eof())
	{
		if(s.getId()==id)
		{
			cout<<"\n\n \t I find This \n"<<s.getId()<<endl;
			viewStud(s);	getch();
			system("cls");
			title("Updating...");
			file.seekp(file.tellg()-sizeof(s));
			addStud(&s,s.getId());
			file.write((char*)&s,sizeof(s));
			file.close();
			cout<<"\n\n \tUpdate recored!!!";
			return 1;
		}
		file.read((char*)&s,sizeof(s));
	}
	file.close();
	return 0;	
}
