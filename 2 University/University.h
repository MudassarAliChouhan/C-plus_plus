#define STUDENT_FILE "Data/Student.dat"
#define COLLAGE_FILE "Data/Institude.dat"
#define STUDENT_TMP "Data/Student.dat.Tmp"
#define COLLAGE_TMP "Data/Institude.dat.Tmp"
#define SEC 1000
class identity
{	
	private:
			
		unsigned int  	id;
		
		char		 	name[25],
						addr[30],
						contact[12];
	public:
		
		int  setId(void);
		void setName(char*);
		void setAddr(char*);
		void setContect(char*);
		
		int  	getId();
		char* 	getName();
		char* 	getAddr();
		char* 	getContect();	
};	
class student:public identity
{
	private:
		char 		  	fName[25],
						compSub[3][9],
						optSub[3][30],
						colge[20],						
						stream[30],
						degree[6];
		unsigned int  	fee, fine;
	public:
		void setFName(char*);
		void setColge(char*);
		void setStream(char*);
		void setDegree(char*);
		void setFee(int);
		void setFine(int);
		void setOptSub(char *, int);
		
		char* getFName();
		char* getColge();
		char* getStream();
		char* getDegree();
		int getFee();
		int getFine();
		char* getCompSub(int);
		char* getOptSub(int);
		~student()
		{
			strcpy( compSub [0] , "Urdu");
			strcpy( compSub [1] , "English");
			strcpy( compSub [2] , "Islamiyat");
		}
		
};
class collage:public identity
{
	private:
	char 				subjects[20][30],
						degrees[7][7];
	public:
		int setSubj(char*,int);
		int setDegree(char*,int);
		
		char* getSubj(int);
		char* getDegree(int);
	
};
#include "Core/output.c"
#include "Core/idintity.cpp"
#include "Subject/subject.cpp"
#include "University/Menu.cpp"
#include "Student/Menu.cpp"
