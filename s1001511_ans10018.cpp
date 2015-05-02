#include <iostream>
using namespace std;
int proj(int* a);
int main()
{
	int num;
	int a[100] = {};
	int c[100];
	do{
		cin >> num;
	} while (num > 101 || num < 1);

	for (int i = 0; i < num; i++)
	{
		cin >> a[i];
	}
	for (int m = 0; m < num; m++)
	{
		proj(a);
	}
	system("pause");
	return 0;
}

int proj(int * a)
{
	for (int k = 0; k < 1000; k++)
	{
		for (int j = 0; j < k; j++)
		{
			if (a[j] / 10000>0)
			{
				a[j] = a[j] + a[j] / 10000 + a[j] / 1000 % 10 * 10 + a[j] / 100 % 10 * 100 + a[j] / 10 % 10 * 1000 + a[j] % 10 * 10000;
				if (a[j] / 10000 >0 && (a[j] / 10000 == a[j] % 10) && (a[j] / 1000 % 10 == a[j] % 100 / 10))
				{
					cout << k << " " << a[j] << endl;
					return 0;
				}
			}
			else if (a[j] / 1000 > 0)
			{
				a[j] = a[j] + a[j] / 1000 + a[j] / 100 % 10 * 10 + a[j] / 10 % 10 * 100 + a[j] % 10 * 1000;
				if (a[j] / 1000 > 0 && (a[j] / 1000 == a[j] % 10) && (a[j] / 100 % 10 == a[j] % 100 / 10))
				{
					cout << k << " " << a[j] << endl;
					return 0;
				}
			}
			else if (a[j] / 100 > 0)
			{
				a[j] = a[j] + a[j] / 100 + a[j] / 10 % 10 * 10 + a[j] % 10 * 100;
				if (a[j] / 100 > 0 && (a[j] / 100 == a[j] % 10))
				{
					cout << k << " " << a[j] << endl;
					return 0;
				}
			}
			else if (a[j] / 10 > 0)
			{
				a[j] = a[j] + a[j] / 10 + a[j] % 10;
				if (a[j] / 10 == a[j] % 10)
				{
					cout << k << " " << a[j] << endl;
					return 0;
				}
			}
			else
			{
				a[j] = a[j] + a[j];
			}
		}
	}
	
}