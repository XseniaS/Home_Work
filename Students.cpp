#include <iostream>
#include<string>
using namespace std;
class Student 
{
private:
    int id;
    string name;
public:
    Student() {};
    void setId(int x) { id = x; };
    int getId() { return id; };
    void setName(string Name) { name = Name; };
    string getName() { return name; };
    void info();
};
void Student::info()
{
    cout << "id: " << id << "   name: " << name << endl;
}
int main()
{
    Student arr[2];
    arr[0].setId(1);
    arr[0].setName("Ivanov Ivan");
    arr[1].setId(2);
    arr[1].setName("Petrov Petr");
    for (int i = 0; i < 2; i++)
        arr[i].info();

    return 0;
}
