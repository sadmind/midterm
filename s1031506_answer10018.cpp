#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	long long n;
	int t;
	int counter=0,con=0;
	int p[100];
	int p2[100];
	ifstream fin("data_uva10018.txt");
	while (fin >> t)
	{
		cout << "Read from file: " << t << endl;
		p[counter] = t;
		counter++;
	}
	for (int i = 0; i < p[0]; i++)
	{
		p2[i] = p[i + 1];
		con++;
	}
	cout << con << " "<< counter << endl;

	system("pause");
	return 0;
}