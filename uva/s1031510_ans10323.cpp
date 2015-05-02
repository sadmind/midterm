#include<iostream>
#include <fstream>
using namespace std;

int main()
{
	int sum = 1, i = 1;
	int t, t2, t3;
	ifstream ifstream("data_uva10323.txt", ios::in);
	ifstream >> t >> t2 >> t3;
	cout << "Read from file: " << t << endl;
	cout << "Read from file: " << t2 << endl;
	cout << "Read from file: " << t3 << endl;

	do
	{
		sum = sum*i++;
	} while (i <= t);
	if (t >= 32)
		cout << "Overflow!\n";
	else if (sum < 10000)
		cout << "Underflow!\n";
	else
		cout << sum << endl;

	sum = 1, i = 1;
	do
	{
		sum = sum*i++;
	} while (i <= t2);
	if (t2 >= 32)
		cout << "Overflow!\n";
	else if (sum < 10000)
		cout << "Underflow!\n";
	else
		cout << sum << endl;

	sum = 1, i = 1;
	do
	{
		sum = sum*i++;
	} while (i <= t3);
	if (t3 >= 32)
		cout << "Overflow!\n";
	else if (sum < 10000)
		cout << "Underflow!\n";
	else
		cout << sum << endl;
	system("pause");
}