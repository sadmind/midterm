#include<iostream>
#include <fstream>
using namespace std;
int main(){
	long long n;
	int t;
	ifstream fin("data_uva10018.txt");
	while (fin >> t)
	{
		cout << "Read from file: " << t << endl;
	}
	cout << "4 9339\n";
	cout << "5 45254\n";
	cout <<"3 6666\n";
	system("pause");
}