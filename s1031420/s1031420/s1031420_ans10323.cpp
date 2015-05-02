#include <iostream>
#include <iomanip>

using namespace std;

unsigned long factor(unsigned long);

int main()
{
	for (int count = 0; count <= 1000; count++)
	{




	}


}

unsigned long factor(unsigned long number)
{
	if (number <= 1)
		return 1;
	else
		return number * factor(number - 1);
}