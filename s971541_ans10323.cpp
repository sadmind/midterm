#include<iostream>
#include <fstream>
using namespace std;
int main(){
	long long n;
	int t;
	ifstream fin("data_uva10323.txt");

	int a = 0, b = 0, c = 0;
//讀第一行
	fin >> t;
	a = t;
	int tmp_a = a;
	for (int i = tmp_a; i > 0; i--)
		tmp_a = tmp_a*i;
	if (a > 13)
		cout << "Overflow!" << endl;
	else if (tmp_a < 10000)
		cout << "Underflow!" << endl;
	else
		cout << tmp_a << endl;
//讀第二行
	fin >> t;
	b = t;
	int tmp_b = b;
	for (int i = tmp_b; i > 0; i--)
		tmp_b = tmp_b*i;
	if (b > 13)
		cout << "Overflow!" << endl;
	else if (tmp_b < 10000)
		cout << "Underflow!" << endl; 
	else
		cout << tmp_b << endl;

//讀第三行
	fin >> t;
	c = t;
	int tmp_c = c;
	for (int i = tmp_c; i > 0; i--)
		tmp_c = tmp_c*i;
	if (c > 13)
		cout << "Overflow!" << endl;
	else if (tmp_c < 10000)
		cout << "Underflow!" << endl; 
	else
		cout << tmp_c << endl;
	system("pause");
	return 0;
}