#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Zakaz 
{
public:
    string fio, time, location;
    int num;
    double price;
public:
    Zakaz() {}
    void menu1(int k);
    void menu2();
    void print_f(Zakaz* prezent, int n);
    int skidka(double sk, int i);
    void print_otmena(Zakaz* prezent, int i);
};
void Zakaz::menu1(int k)
{
    if (k == 0)
    {
        cout << "Добрый день! Чем могу помочь?\n";
        cout << "1. Я хочу сделать заказ.\n";
        cout << "0. Мне ничего не нужно, спасибо.\n\n";
    }
    else
    {
        cout << "Хотите сделать что-то ещё?\n";
        cout << "2. Я хочу изменить заказ.\n";
        cout << "3. Я хочу узнать информацию о заказе.\n";
        cout << "4. Я хочу отменить заказ.\n";
        cout << "0. Мне больше ничего не нужно, спасибо.\n\n";
    }
}
void Zakaz::menu2()
{
    cout << "\n1. ФИО\n";
    cout << "2. Дату и время доставки\n";
    cout << "3. Место доставки\n";
    cout << "4. Цену заказа\n";
    cout << "0. Ничего\n\n";
}
int Zakaz::skidka(double sk, int i)
{
    double skid;
    skid = sk - sk * 0.1;
    return skid;
}
void Zakaz::print_f(Zakaz* prezent, int n)
{
    ofstream list;

    list.open("C:\\Users\\Nameless\\OneDrive\\Документы\\VS project\\project(class)\\List.txt");
    for (int i = 0; i < n; i++)
    {
        double sk = prezent[i].price;
        list << "Номер заказа: " << prezent[i].num << endl;
        list << "ФИО получателя: " << prezent[i].fio << endl;
        list << "Дата и время доставки: " << prezent[i].time << endl;
        list << "Место доставки: " << prezent[i].location << endl;
        list << "Цена заказа: " << prezent[i].price << endl;
        list << "Цена заказа со скидкой: " << skidka(sk, i) << endl;
        list << "Ваша выгода составила: " << prezent[i].price - skidka(sk, i);
        cout << endl << endl;
    }
    list.close();
}
void Zakaz::print_otmena(Zakaz* prezent, int i)
{
    ofstream otmena;
    otmena.open("C:\\Users\\Nameless\\OneDrive\\Документы\\VS project\\project(class)\\Otmena.txt");
    otmena << "Номер заказа: " << prezent[i].num << endl;
    otmena << "ФИО получателя: " << prezent[i].fio << endl;
    otmena << "Дата и время доставки: " << prezent[i].time << endl;
    otmena << "Место доставки: " << prezent[i].location << endl;
    otmena << "Цена заказа: " << prezent[i].price << endl << endl;
    otmena.close();
}

void main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int s = 1, n = 0, t = 1, k = 0, num;
    ofstream list;
    ofstream otmena;
    cout << "Поздравляем, Вы стали участником новогодней акции. Все заказы со скидкой 10%!\n\n";
    cout << "Добрый день! Чем могу помочь?\n";
    cout << "1. Я хочу сделать заказ.\n";
    cout << "0. Мне ничего не нужно, спасибо.\n\n";
    cin >> s;
    system("cls");
    while (s != 0)
    {
        if (s == 1)
        {
            cout << "Сколько заказов вы хотите сделать?\n";
            cin >> n;
            cout << endl;
            break;
        }
        else
        {
            cout << "Ошибка. Возможно вы случайно нажали не ту кнопку, попробуйте ещё раз.\n\n";
            cout << "Добрый день! Чем могу помочь?\n";
            cout << "1. Я хочу сделать заказ.\n";
            cout << "0. Мне ничего не нужно, спасибо.\n\n";
            cin >> s;
            system("cls");
        }
    }
    Zakaz* prezent = new Zakaz[n];
    while (s != 0)
    {

        switch (s)
        {
        case 1:
        {
            if (k != 0)
            {
                cout << "Ошибка. Возможно вы случайно нажали не ту кнопку, попробуйте ещё раз.\n\n";
                break;
            }
            for (int i = 0; i < n; i++)
            {
                prezent[i].num = i;
                cout << "Номер заказа: " << prezent[i].num << endl;
                cin.ignore();
                int sk;
                cout << "Введите ФИО получателя: "; getline(cin, prezent[i].fio);
                cout << "Ведите дату и время доставки: "; getline(cin, prezent[i].time);
                cout << "Введите место доставки: "; getline(cin, prezent[i].location);
                cout << "Введите цену заказа: "; cin >> prezent[i].price; cout << endl;
                sk = prezent[i].price;
                cout << "Цена заказа со скидкой: " << prezent[i].skidka(sk, i) << endl;
                cout << "Ваша выгода составила: " << prezent[i].price - prezent[i].skidka(sk, i) << endl;
                system("pause");
                prezent[i].print_f(prezent, n);
                cout << endl;
            }
            system("cls"); k++;
            break;
        }
        case 2:
        {
            if (n == 0)
            {
                cout << "Ошибка. Возможно вы случайно нажали не ту кнопку, попробуйте ещё раз.\n\n";
                break;
            }
            cout << "Скажите номер заказа, в который Вы хотите внести изменения\n";
            cin >> num;
            system("cls");
            int z = 0;
            while (z < n)
            {
                if (num == prezent[z].num)
                {
                    while (t != 0)
                    {
                        prezent[z].print_f(prezent, n);
                        cout << "Что Вы бы хотели изменить?\n";
                        prezent[z].menu2();
                        cin >> t;
                        cin.ignore();
                        system("cls");
                        switch (t)
                        {
                        case 1:
                        {
                            cout << "Новое ФИО: "; getline(cin, prezent[num].fio);
                            system("cls");
                            break;
                        }
                        case 2:
                        {
                            cout << "Новое время и место доставки: "; getline(cin, prezent[num].time);
                            system("cls");
                            break;
                        }
                        case 3:
                        {
                            cout << "Новый адрес: "; getline(cin, prezent[num].location);
                            system("cls");
                            break;
                        }
                        case 4:
                        {
                            cout << "Новая цена заказа: "; cin >> prezent[num].price;
                            system("cls");
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Ошибка. Возможно вы случайно нажали не ту кнопку, попробуйте ещё раз.\n\n";
                            system("cls");
                            break;
                        }
                    }
                    break;
                }
                if ((z == n - 1) && (num != prezent[z].num))
                {
                    cout << "Заказа под таким номером нет\n\n";
                    cout << "Введите существующий номер заказа\n";
                    cin >> num;
                    z = 0;
                    system("cls");
                }
                else
                    z++;
            }
            t = 1;
            prezent[z].print_f(prezent, n);
            system("cls");
            break;
        }
        case 3:
        {
            if (n == 0)
            {
                cout << "Ошибка. Возможно вы случайно нажали не ту кнопку, попробуйте ещё раз.\n\n";
                break;
            }
            cout << "Скажите номер заказа, о котором вы хотите узнать\n";
            cin >> num;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                if (num == prezent[i].num)
                {
                    cout << "Номер заказа: " << prezent[i].num << endl;
                    cout << "ФИО получателя: " << prezent[i].fio << endl;
                    cout << "Дата и время доставки: " << prezent[i].time << endl;
                    cout << "Место доставки: " << prezent[i].location << endl;
                    cout << "Цена заказа: " << prezent[i].price << endl;
                    cout << "Цена заказа со скидкой: " << prezent[i].price - prezent[i].price * 0.1 << endl << endl;
                    cout << endl;
                    break;
                }
                if ((i == n - 1) && (num != prezent[i].num))
                {
                    cout << "\nЗаказа под таким номером нет\n\n";
                    system("pause");
                    system("cls");
                }
            }
            break;
        }
        case 4:
        {
            if (n == 0)
            {
                cout << "Ошибка. Возможно вы случайно нажали не ту кнопку, попробуйте ещё раз.\n\n";
                break;
            }
            cout << "Введите номер заказа, который Вы хотите удалить\n";
            cin >> num;
            for (int i = 0; i < n; i++)
            {
                if (num == prezent[i].num)
                {
                    prezent[i].print_otmena(prezent, num);
                    for (int i = num; i < n - 1; i++)
                    {
                        prezent[i].num = i + 1;
                        prezent[i].fio = prezent[i + 1].fio;
                        prezent[i].time = prezent[i + 1].time;
                        prezent[i].location = prezent[i + 1].location;
                        prezent[i].price = prezent[i + 1].price;
                    }
                    n--;
                    prezent[i].print_f(prezent, n);
                    cout << endl;
                    cout << "\nЗаказ отменён\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
                if ((i == n - 1) && (num != prezent[i].num))
                {
                    cout << "\nЗаказа под таким номером нет\n\n";
                    system("pause");
                    system("cls");
                }
            }
            system("cls");
            break;
        }
        default:
            cout << "Ошибка. Возможно, Вы случайно нажали не ту кнопку, попробуйте ещё раз.\n\n";
            break;
        }
        if (k == 0)
        {
            cout << "Добрый день! Чем могу помочь?\n";
            cout << "1. Я хочу сделать заказ.\n";
            cout << "0. Мне ничего не нужно, спасибо.\n\n";
        }
        else
        {
            cout << "Хотите сделать что-то ещё?\n";
            cout << "2. Я хочу изменить заказ.\n";
            cout << "3. Я хочу узнать информацию о заказе.\n";
            cout << "4. Я хочу отменить заказ.\n";
            cout << "0. Мне больше ничего не нужно, спасибо.\n\n";
        }
        cin >> s;
        system("cls");
    }
    if (n == 0 || s == 0)
        cout << "До свидания!\n";
}