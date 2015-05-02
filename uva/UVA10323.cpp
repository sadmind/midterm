#include<iostream>

using namespace std;

int main()
{
	int number;

	cin >> number;

	for (int i = number-1; i >= 1; i--)
	{
		number = number*i;
	}
	if (number < 10000)
	{
		cout << " Underflow!" << endl;
	}
	else if (number>6227020800)
	{
		cout << "Overflow!" << endl;

	}
	else
	{

		cout << number << endl;


	}
	system("pause");
	return 0;
}