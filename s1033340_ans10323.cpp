#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int num[3][1];
	for (int x = 0; x < 3; x++)
	{
		cin >> num[x][1];
	}
	for (int y = 0; y < 3; y++)
	{
		long long int sum = 1;
		int k = num[y][1];
		while (k>0)
		{
			sum *= k;
			k--;
		}
		if (num[y][1]>13)
			cout << "Overflow!" << endl;
		else if (num[y][1]<7)
			cout << "Underflow!" << endl;
		if (num[y][1] <= 13 && num[y][1] >= 7)
			cout << sum << endl;
	}
	system("pause");
	return 0;
}