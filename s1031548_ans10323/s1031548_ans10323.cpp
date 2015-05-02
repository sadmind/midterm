#include<iostream>
#include<string>
#include <fstream>
using namespace std;
int Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	
	return n * Factorial(n - 1);
}
int main()
{
	long long n = 0;
	int t;
	ifstream fin("data_uva10323.txt",ios::in);
	if (!fin)
	{
		cout << "ERROR!" << endl;
	}
	while (fin >> t)
	{
		cout << "Read from file: " << t << endl;
	}


	while (!fin.eof())
	{
		if (Factorial(n) > 6227020800)
		{
			cout << "Overflow!" << endl;
		}
		else if(Factorial(n) < 10000)
		{
			cout << "Underflow!" << endl;
		}
		else
		{
			cout << Factorial(n) << endl;
		}
	}
	
	system("pause");
	return 0;
}