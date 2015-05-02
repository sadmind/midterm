// PG2String test program.
#include <iostream>

#include "s1031506_string.h" // include definition of class String
using namespace std;
int main()
{
	//To be or not to be, that is the question;
	char * str1 = "to be "; //It's ended with '\0' automatically
	char * str2 = "the ";
	char * str3 = "or not to be";
	char * str_tester = "Ha";
	String A(str1);
	String X(str2);
	String B = X;
	String C = "or not to be";
	cout << "A = str1: " << A << endl;
	cout << "B = X = str2: " << B << " = " << X << endl;
	cout << "C = str3: " << C << " = " << str3 << endl;

	String D = A + C;
	cout << "D = A + C: " << D << endl;
	D = A + str3;
	cout << "D = A + str3: " << D << endl;
	D = str1 + C;
	cout << "D = str1 + C: " << D << endl;

	cout << "-------------------------------" << endl;

	cout << "D push ',': ";
	D.push_back(',');
	cout << D << endl;
	cout << "D pop_back: ";
	D.pop_back();
	cout << D << endl;
	
	cout << "-------------------------------" << endl;
	
	String STR = D;
	String E = ", that is cool question";
	String F = ", that is (the )question";
	String G = "the ";
	STR.append(F);
	cout << "STR = D append F: " << STR << endl;
	STR.erase(28,6);
	cout << "STR erase 28-34: " << STR << endl;
	STR.insert(28, G); 
	cout << "STR insert G: " << STR << endl;
	STR.erase(28,4);
	cout << "STR erase 28-34: " << STR << endl;
	STR.insert(28, E, 10, 5); 
	cout << "STR insert E (10-14): " << STR << endl;
	
	cout << "-------------------------------" << endl;

	String STR2 = E.substr(10,4);
	cout << "find \"cool\" in the STR: " << STR.find(STR2) << endl;
	STR2 = "cXXL";
	cout << "Let STR2 = cXXL: " << STR2 << endl;
	cout << "find \"cXXL\" in the STR: " << STR.find(STR2) << endl;
	cout << "find first \"cXXL\" in the STR: " << STR.find_first_of(STR2) << endl;

	cout << "print the first and last char of STR: " << STR.front() << " : " << STR.back() << endl;
	
	cout << "-------------------------------" << endl;

	cout << "Rebuild STR2 word by word: ";
	String STR3 = "";
	for(int i = 0; i < STR2.length(); i++)
		STR3.push_back(STR2[i]);
	cout << STR3 << endl;
	
	cout << STR3 << " is equal to " << STR2 << "? " << (STR3 == STR2) << endl;
	STR3 = STR3 + "-ZZZ";
	cout << STR3 << " is equal to " << STR2 << "? " << (STR3 == STR2) << endl;
	
	STR3.pop_back();
	STR3.pop_back();
	cout << "STR3 pop 2 char = " << STR3 << endl;

	STR3.clear();
	cout << "STR3 clear all char = " << STR3 << endl;

	cout << "-------------------------------" << endl;
	cout << "Current STR3 [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;
	
	cout << "STR3 append STR2 = " << STR3.append(STR2);
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;

	STR3.reserve(20);
	cout << "STR3 reserve to 20 = " << STR3 << endl;
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;

	STR3.shrink_to_fit();
	cout << "STR3 shrink_to_fit = " << STR3 << endl;
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;
	
	STR3.resize(20, 'c');
	cout << "STR3 resize to 20 = " << STR3 << endl;
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;
		
	system("pause");
	return 0;
}