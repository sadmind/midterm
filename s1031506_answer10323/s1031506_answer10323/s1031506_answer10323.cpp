#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	long long n;
	int t;
	int p[10] = {};
	int counter = 0;
	ifstream fin("data_uva10323.txt");

	while (fin >> t)
	{
		p[counter] = t;
		counter++;
	}

	int f[10] = {1,1,1,1,1,1,1,1,1,1};
	int temp = 0;
	for (int j = 0; j < counter; j++)
	{
		for (int i = 1; i < p[j]+1 ; i++)
		{
			temp = i * f[j];
			f[j] = temp;
		}
	}

	for (int i = 0; i < counter; i++)
	{
		if (p[i]>16)
			cout << "Overflow!" << endl;
		else if (f[i] < 10000)
			cout << "Underflow!" << endl;
		else
			cout << f[i] << endl;
	}
	system("pause");
	return 0;
}