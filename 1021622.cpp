#include<iostream>
#include <fstream>
using namespace std;
unsigned long factorial(unsigned long number);
int main(){
	long long n;
	int t;
	ifstream fin("data_uva10323.txt");
	while (fin >> t)
	{ 
		cout << "Read from file: " <<t<<" = "<< factorial(t)<< endl;
		
	}

	system("pause");
	return 0;
}
unsigned long factorial(unsigned long number)
{
	if (number <= 1)
	{
		return 1;
	}
	else
	{
		return number*factorial(number - 1);
	}
}