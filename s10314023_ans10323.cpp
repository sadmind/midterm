#include<iostream>
#include <fstream>
using namespace std;


int main()
{
	int total1 = 1;
	int total2 = 1;
    int total3=1;
	long long n;
	int t=2;
	int u = 10;
	int v = 100;
	
		for (int i = 1; i <= t; i++)
		{
			total1 *= i;
		}
		if (total1 < 10000 && total1 != 0)
			cout << "Underflow!" << endl;

		else if (total1==0)
			cout << "Overflow!" << endl;
		else
			cout << total1 << endl;



		for (int i = 1; i <=u; i++)
		{
			total2*=i ;
		}
		if (total2 < 10000 && total2 != 0)
			cout << "Underflow!" << endl;

		else if (total2==0)
			cout << "Overflow!" << endl;
		else

			cout << total2 << endl;



		for (int i = 1; i <= v; i++)
		{
			total3*=i;
		}
		if (total3 < 10000 && total3!=0)
			cout << "Underflow!" << endl;

		else if (total3 ==0)
			cout << "Overflow!" << endl;
		else
			cout << total3<<endl;


		system("pause");
		return 0;

	
}