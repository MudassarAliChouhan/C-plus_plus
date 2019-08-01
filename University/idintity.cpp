	// Set Functions :)

int identity::setId(void)
{
	srand(time(0));
	id = (rand()%100)+1;
	return id;
}
void identity::setName(char *n)
{
	strcpy(name , n);
}
void identity::setAddr(char *a)
{
	strcpy(addr , a);
}
void identity::setContect(char *c)
{
	strcpy(contact , c);
}
	// Get Functions :)
int	   identity::getId()
{
	return id;
}
char* identity::getName()
{
	return name;
}
char* identity::getAddr()
{
	return addr;
}
char* identity::getContect()
{
	return contact;
}
