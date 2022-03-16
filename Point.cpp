#include <iostream>
#include <cmath>
using namespace std;
class Point
{
public:
	int x, y;
	int distance(Point a);
	void s(int a, int b)
	{
		if (a >= b)
			cout << "\nНаибольшее расстояние до начала координат = " << a << endl;
		if (a < b)
			cout << "\nНаибольшее расстояние до начала координат = " << b << endl;
	};
	void s(int a, int b, int c)
	{
		if ((a >= b)&&(a >= c))
			cout << "\nНаибольшее расстояние до начала координат = " << a << endl;
		else if ((b >= a)&&(b >= c))
			cout << "\nНаибольшее расстояние до начала координат = " << b << endl;
		else
			cout << "\nНаибольшее расстояние до начала координат = " << c << endl;
	};
	void s(double* d, int n)
	{
		double max = 0;
		for (int i = 0; i < n; i++)
		{
			if (d[i] > max)
				max = d[i];
		}
		cout << "\nНаибольшее расстояние до начала координат = " << max << endl;
	};
};
int Point::distance(Point a)
{
	double d;
	d = sqrt(a.x ^ 2 + a.y ^ 2);
	return d;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество точек: "; cin >> n;
	Point* a = new Point[n];
	double* d = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите координату х " << i + 1 << " точки: "; cin >> a[i].x; cout << endl;
		cout << "Введите координату у " << i + 1 << " точки: "; cin >> a[i].y; cout << endl;
	}
	for (int i = 0; i < n; i++)
		d[i] = a[i].distance(a[i]);

	if(n >=2)
		a[0].s(d[0], d[1]);
	if(n >= 3)
		a[0].s(d[0], d[1], d[2]);
	a[0].s(d, n);
}
