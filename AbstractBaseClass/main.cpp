//AbstractBaseClass
#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void sound() = 0; 
};
class Cat:public Animal {};
class Tiger:public Cat
{
public:
	void sound()override
	{
		cout << "RRRRRR" << endl; 
	}
};
class Homecat : public Cat
{
public:
	void sound()override
	{
		cout << "MMMIIAAYY" << endl; 
	}
};
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Hello AbstractBaseClasses";
	//Animal animal; 
	//Cat cat; 
	Tiger tiger; 
	tiger.sound(); 
	Homecat home;
	home.sound(); 
}