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
