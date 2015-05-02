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