#include <iostream>
using namespace std;
class Sotrudnik
{
public:
    string name;
    int salary;
    void info(int salary)
    {
        cout << "salary: " << salary << endl;
    }
};
class Programmer :public Sotrudnik
{
public:
    string name;
    int salary;
    string project;
    void info(int salary, string project)
    {
        cout << "salary: " << salary << endl;
        cout << "project: " << project << endl << endl;
    }
    void info(Programmer a)
    {
        cout << "name: " << a.name << endl;
        cout << "salary: " << a.salary << endl;
        cout << "project: " << a.project << endl << endl;
    }
};
int main()
{
    Programmer a;
    a.name = "Petr";
    a.salary = 345;
    a.project = "game";
    a.info(a.salary, a.project);
    a.info(a);
    Sotrudnik b;
    b.name = "Ivan";
    b.salary = 123;
    b.info(b.salary);
}