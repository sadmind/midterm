#include<iostream>
using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	int xa=x, ya=y, za=z, xb=x, yb=y, zb=z;
	for (int i = 0; i < xb; i++)
	{
		x--;
		xa = xa*x;
	}
	if (xa < 10000)
		cout << "Underflow";
	else if (xa>6227020800)
		cout << "Overflow";
	else
		cout << xa;
	for (int i = 0; i < yb; i++)
	{
		y--;
		ya = ya*y;
	}
	if (ya < 10000)
		cout << "Underflow";
	else if (ya>6227020800)
		cout << "Overflow";
	else
		cout << ya;
	for (int i = 0; i < zb; i++)
	{
		z--;
		za = za*z;
	}
	if (za < 10000)
		cout << "Underflow";
	else if (za>6227020800)
		cout << "Overflow";
	else
		cout << za;
	system("pause");
	return 0;
}