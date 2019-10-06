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
	{
		strcpy(sub, compSub[i]);
		return sub;		
	}
	return 0;
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
