#include<iostream>
#include <fstream>
using namespace std;

long long  factorial(int iNumber)
{
	if (iNumber == 0)
		return 1;
	else
		return iNumber*factorial(iNumber - 1);
}
int main()
{
	long long n;
	int t;
	ifstream fin("data_uva10323.txt");
	while (fin >> t)
	{
		cout << "Read from file: " << t << endl;
		n = factorial(t);
		if (!(factorial(t) - factorial(t - 1)))
		{
			cout << "Overflow!" << endl;
			continue;
		}
		else if (n < 10)
		{
			cout << "Underflow!" << endl;
			continue;
		}
		else
			cout << n << endl;
	}
	system("pause");
	return 0;
}
