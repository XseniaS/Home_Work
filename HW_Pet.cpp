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
class Pet :public Dog
{
private:
	string pet_name;
	string own_name;
	string address;
public:
	Pet() {}
	void setName() { cin >> pet_name; };
	string getName() { return pet_name; };
	void setOwn() { cin >> own_name; };
	string getOwn() { return own_name; };
	void setAd() { cin >> address; };
	string getAd() { return address; };
};

int main()
{
	int n = 0;
	Dog one("Neapolitan Mastiff", "Large", 5, "Black");
	one.print();

	Dog two("Maltese", "Small", 2, "White");
	two.print();

	Dog three("Chow Chow", "Medium", 3, "Brown");
	three.print();

	cout << "\n\nWhat kind of dog do you want to make a pet?\n" << endl;
	cin >> n;
	system("cls");
	Pet x;
	if (n == 1)
	{
		x.breed = one.breed;
		x.age = one.age;
		x.color = one.color;
		x.size = one.size;
	}
	else if (n == 2)
	{
		x.breed = two.breed;
		x.age = two.age;
		x.color = two.color;
		x.size = two.size;
	}
	else if (n == 3)
	{
		x.breed = three.breed;
		x.age = three.age;
		x.color = three.color;
		x.size = three.size;
	}
	else
	{
		cout << "Error";
		return 0;
	}
	cout << "Enter the pet's name\n";
	x.setName();
	cout << "Enter the name of the pet owner\n";
	x.setOwn();
	cout << "Enter the address\n";
	x.setAd();
	system("cls");
	cout << "**** Details of  Dog ****";
	cout << "\nPet name       :  " << x.getName();
	cout << "\nPet owner       :  " << x.getOwn();
	cout << "\nPet address       :  " << x.getAd();
	cout << "\nPet breed       :  " << x.breed;
	cout << "\nPet size       :  " << x.size;
	cout << "\nPet age       :  " << x.age << " years";
	cout << "\nPet color       :  " << x.color;
	cout << "\n-------------------------------";
	return 0;
}