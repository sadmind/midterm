#include <iostream>
#include "midterm.cpp"
#include "PG2String.h"
#include <cstring>
using namespace std;

int main()
{
	char * str1 = "to be ";
	char * str2 = "the ";
	char * str3 = "or not to be ";
	char * str_tester = "Ha";
	String A(str1);
	String X(str2);
	String B = X;
	String C = "or not to be";
	cout << "A = str1:" << A << endl;
	cout << "B = X =str2: " << B << endl;


}