#include<iostream>
#include <fstream>
using namespace std;
int main(){
	long long n;
	int t;
	int sum[1000];
	int a[1000]; 
	ifstream fin("data_uva10323.txt");
	while (fin >> t)
	{
		cout << "Read from file: " << t << endl;
		int n = t;
		
		for (int i = 0; i < n; i++)
		{
			a[i] = i+1;
		}
		sum[0] = a[0];
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 1; j< n; j++)
			{
				sum[j] = sum[i] * a[j];
			}		
		}
		if (sum[n] > 6227020800)
		{
			cout << "Overflow!" << endl;
		}
		else if (sum[n] < 10000)
		{
			cout << "Underflow!" << endl;
		}
		else
		{
			cout << sum[n] << endl;
		}
	}
	system("pause");
	return 0;
}