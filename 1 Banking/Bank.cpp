#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
 
class Bank
{
	private:
		int accNo, age, date, time ; 
		char name[30];
	public:
		void show();
		void get();
		void write_r();
		void search(char *n);
		void del(char *n);
		void edit(char *n);
		void viewAll();
};
		
int main()
{
	/// This is main function. 
	Bank bk;
	//bk.get();
	//bk.write_r();
	bk.viewAll();
	//bk.edit("Nadeem");
	getch();
}
void Bank::edit(char *n)
{
	fstream file;
	file.open("Bank.dat",ios::in|ios::ate|ios::out|ios::binary);
	file.seekg(0);	
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(!strcmp(n,name))
		{
			file.seekp(file.tellg()-sizeof(*this));
			get();
			file.write((char*)this,sizeof(*this));
		}
		file.read((char*)this,sizeof(*this));
	}
}
void Bank::del(char *n)
{
	ofstream fout;
	ifstream fin;
	fin.open("Bank.dat",ios::in|ios::binary);
	fout.open("Bank.dat.tmp",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(strcmp(n,name))
			fout.write((char*)this,sizeof(*this));
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Bank.dat");
	rename("Bank.dat.tmp","Bank.dat");
}
void Bank::viewAll()
{
	ifstream fin;
	fin.open("Bank.dat",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		show();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void Bank::show()
{
	cout << "Name: " << name << endl;
	cout << "Account No: " << accNo << endl;
	cout << "Current Time: " << time << endl;
	cout << "Today Date: " << date << endl;
	cout << "Age: " << age << endl << endl;
}
void Bank::get()
{
	cout << "Name ";
	cin >> name;
	//cin >> accNo;
	//cin >> time;
	//cin >> date;
	cout << "Age ";
	cin >> age;
}
void Bank::write_r()
{
	ofstream fout;
	fout.open("Bank.dat",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}
















