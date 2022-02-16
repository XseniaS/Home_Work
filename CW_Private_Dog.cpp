#include <iostream>
using namespace std;
class Dog
{
private:
	string breed;
	string size;
	int age;
	string color;
public:
	Dog() {};
	Dog(string breed, string size, int age, string color)
	{
		this->breed = breed;
		this->size = size;
		this->age = age;
		this->color = color;
	};
	void setBreed(string s) { breed = s; };
	string getBreed() { return breed; };
	void setSize(string s) { size = s; };
	string getSize() { return size; };
	void setColor(string s) { color = s; };
	string getColor() { return color; };
	void setAge(int a) { age = a; };
	int getAge() { return age; }
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
protected:
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
	Dog one;
	one.setBreed("Neapolitan Mastiff");
	one.setSize("Large");
	one.setAge(5);
	one.setColor("Black");
	one.print();

	Dog two;
	two.setBreed("Maltese");
	two.setSize("Small");
	two.setAge(2);
	two.setColor("White");
	two.print();

	Dog three;
	three.setBreed("Chow Chow");
	three.setSize("Medium");
	three.setAge(3);
	three.setColor("Brown");
	three.print();

	cout << "\n\nWhat kind of dog do you want to make a pet?\n" << endl;
	cin >> n;
	system("cls");
	Pet x;
	if (n == 1)
	{
		x.setBreed(one.getBreed());
		x.setAge(one.getAge());
		x.setColor(one.getColor());
		x.setSize(one.getSize());
	}
	else if (n == 2)
	{
		x.setBreed(two.getBreed());
		x.setAge(two.getAge());
		x.setColor(two.getColor());
		x.setSize(two.getSize());
	}
	else if (n == 3)
	{
		x.setBreed(three.getBreed());
		x.setAge(three.getAge());
		x.setColor(three.getColor());
		x.setSize(three.getSize());
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
	cout << "\nPet breed       :  " << x.getBreed();
	cout << "\nPet size       :  " << x.getSize();
	cout << "\nPet age       :  " << x.getAge() << " years";
	cout << "\nPet color       :  " << x.getColor();
	cout << "\n-------------------------------";
	return 0;
}