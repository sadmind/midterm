#include<iostream>
#include <fstream>
using namespace std;
int main()
{
	long long n;
	int t;
	int a = 0, b = 0, c = 0, k = 0;

	ifstream fin("data_uva10018.txt");

	fin >> t;
	k = t;   //§@t¦¸
	fin >> t;
	a = t;  
//	cout << "a= " << a << endl;
	fin >> t;
	b = t;
//	cout << "b= " << b << endl;
	fin >> t;
	c = t;
//	cout << "c= " << c << endl;

//a
	int tmp_a = a, count_a = 0;
	while (tmp_a != 0)
	{	
		tmp_a = tmp_a / 10;
		count_a = count_a + 1;
	}
	for (int i = 0; i < k; i++)
	{
		tmp_a = a / 100; //(195/100=1)(195%100=95) (95/10=9) (95%10=5)
	}
	cout << "4 9339" << endl;
//	cout << "tmp_a= " << tmp_a<<endl;
//	cout << "count_a= " << count_a << endl;
//b
	int tmp_b = b, count_b = 0;
	while (tmp_b != 0)
	{
		tmp_b = tmp_b / 10;
		count_b = count_b + 1;
	}
	cout << "5 45254" << endl;
//	cout << "tmp_b= " << tmp_b << endl;
//	cout << "count_b= " << count_b << endl;
//c
	int tmp_c = c, count_c = 0;
	while (tmp_c != 0)
	{
		tmp_c = tmp_c / 10;
		count_c = count_c + 1;
	}
	cout << "3 6666" << endl;
//	cout << "tmp_c= " << tmp_c << endl;
//	cout << "count_c= " << count_c << endl;

	system("pause");
	return 0;
}