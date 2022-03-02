#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int id;
    string name;
public:
    Student() {};
    void setId() { cin >> id; };
    int getId() { return id; };
    void setName() { getline(cin, name); };
    string getName() { return name; };
    void info();
};
void Student::info()
{
    cout << "id: " << id << "   name: " << name << endl;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    cout << "Введите кол-во студентов\n";
    cin >> size;
    Student* arr = new Student[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Введите id:    ";
        arr[i].setId();
        cin.ignore();
        cout << "Введите имя:   ";
        arr[i].setName();
    }
    system("cls");
    for (int i = 0; i < size; i++)
        arr[i].info();
    return 0;
}