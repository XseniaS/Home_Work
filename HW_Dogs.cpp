#include <iostream>
using namespace std;
class Dog
{
public:
	string breed;
	string size;
	int age;
	string color;
public:
	Dog() {}
	Dog(string breed, string size, int age, string color)
	{
		this->breed = breed;
		this->size = size;
		this->age = age;
		this->color = color;
	};
	void print();
	void eat();
	void sleep();
	void sit();
	void run();
};

void Dog::print()
{
	cout << "\n\n**** Details of  Dog ****";
	cout << "\nDog breed       :  " << breed;
	cout << "\nDog size       :  " << size;
	cout << "\nDog age       :  " << age << " years";
	cout << "\nDog color       :  " << color;
	cout << "\n-------------------------------";
}
void Dog::eat()
{
	cout << "\nThe dog is hungry";
}
void Dog::sleep()
{
	cout << "\nThe dog wants to sleep";
}
void Dog::sit()
{
	cout << "\nThe dog is sitting";
}
void Dog::run()
{
	cout << "\nThe dog runs";
}
int main()
{
	Dog one("Neapolitan Mastiff", "Large", 5, "Black");
	one.print();
	one.sleep();

	Dog two("Maltese", "Small", 2, "White");
	two.print();
	two.run();
	two.eat();

	Dog three("Chow Chow", "Medium", 3, "Brown");
	three.print();
	three.sit();
	return 0;
}