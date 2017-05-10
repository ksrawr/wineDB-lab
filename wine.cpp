// wine.cpp
#include "wine.h"

Wine::Wine()
{
}

Wine::Wine(string n, int v,
int s, double p, string t)
{
	name = n;
	vintage = v;
	score = s;
	price = p;
	type = t;
}

void Wine::setInfo(string n, int v,
int s, double p, string t)
{
	name = n;
	vintage = v;
	score = s;
	price = p;
	type = t;
}

void Wine::setPrice(double p)
{
	price = p;
}

string Wine::getName() const
{
	return name;
}

int Wine::getPrice() const
{
	return price;
}

void Wine::printInfo()
{
	cout << name;
	cout << "\t" << vintage;
	cout << "\t" << score;
	cout << "\t" << price;
	cout << "\t" << type;
}

void printPersoninfo(List< Wine > & wineList)
{
	Wine * f;
	f = (Wine *) wineList.getInfo(0);
	f->printInfo();
	
	ListNode< Wine > *currentPtr;
	
	currentPtr = personList.getFirstPtr();
	
	cout << "The Wine list is: \n";
	
	while( currentPtr != 0 )
	{
		f = (Wine *) currentPtr;
		f->printInfo();
		currentPtr = currentPtr->getNextptr();
	}
}
