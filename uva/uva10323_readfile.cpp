#include<iostream>
#include <fstream>
using namespace std;
int main(){
	long long n;
	int t;
	ifstream fin("data_uva10323.txt");  
	   while( fin >> t ) 
	   {    
	       cout << "Read from file: " << t << endl;  
	   }
	system("pause");
	return 0;
}
if (factorial(t)>6227020800)
cout << t << " Overflow! " << endl;
if (factorial(t) < 10000)
	cout << t << endl << factorial(t) << "Underflow!" << endl;
else
cout << t << endl << factorial(t) << endl;