#include <string>
#include <iostream>
#include <conio.h>

using namespace std;
const int LEN = 80;

class employee
{
private:
	char name [LEN];
	unsigned long number;
public:
	void getdata()
	{
		cout<<"\nВведiть прiзвище:";cin>>name;
		cout<<"\nВведiть номер:";cin>>number;
	}
	void putdata() const
	{
		cout<<"\nПрiзвище:"<<name;
		cout<<"\nНомер:"<<number;
	}
};

class person:public employee
{
private:
	char title[LEN];
	double dues;
public:
	void getdata()
	{
		employee::getdata();
		cout<<"Введiть посаду:";cin>>title;
		cout<<"Введiть номер :";cin>>dues;
	}
	void putdata()const
	{
		employee::putdata();
		cout<<"\nПосада:"<<title;
		cout<<"\nНомер :"<<dues;
	}
};

class worker:public employee
{
private:
	int pubs;
public:
	void getdata()
	{
	employee::getdata();
	cout<<"Введiть робочий час (в сутки):";cin>>pubs;
	}
	void putdata() const
	{
	employee::putdata();
	cout<<"\nЧас:"<<pubs;
	}
};

class ingeneer:public employee
{
};

int main()
{
	setlocale(LC_ALL,"Russian");
	person m1,m2;
	worker s1;
	ingeneer l1;

	cout<<endl;
	cout<<"\nВвод Інформація про першого служащого";
	m1.getdata();

	cout<<"\nВвод Інформація про другого служащий";
	m2.getdata();
	
	cout<<"\nВвод інформація про рабочого";
	s1.getdata();

	cout<<"\nВвод інформація про інженера";
	l1.getdata();

	cout<<"\nІнформація про першого служащого:";
	m1.putdata();

	cout<<"\nІнформація про другого служащого";
	m2.putdata();

	cout<<"\nІнформація про робочого";
	s1.putdata();

	cout<<"\nІнформація про інженера";
	l1.putdata();
	cout<<endl;
	getch();
	return 0;
}
