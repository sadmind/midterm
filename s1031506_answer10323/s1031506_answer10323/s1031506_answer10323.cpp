#include <iostream>

using namespace std;

int main()
{
	int f = 1;
	int temp = 0;
	int time;
	cout << "Please input the number: " << endl
		<< "? ";
	cin >> time;
	for (int i = 1; i < time+1; i++)
	{
		temp = i * f;
		f = temp;
	}

	if (f < 10000)
		cout << "Underflow!" << endl;
	else if (f > 6227020800)
		cout << "Overflow!" << endl;
	else
		cout << f << endl;

	system("pause");
	return 0;
}