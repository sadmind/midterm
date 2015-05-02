#include<iostream>
#include <fstream>
using namespace std;
int main(){
	long long t;
	ifstream fin("data_uva10323.txt");  
	   while( fin >> t ) 
	   {    
	       cout << "Read from file: " << t << endl;
		   int n = t;
		   if (t < 14)
		   {
			   while (n > 1)
			   {
				   n--;
				   t = t*n;
			   }
			   if (t < 10000)
				   cout << "Underflow!" << endl;
			   else
				   cout << t << endl;
		   }
		   else
			   cout << "Overflow!" << endl;
	   }
	system("pause");
	return 0;
}