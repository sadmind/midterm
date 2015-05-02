#include<iostream>
using namespace std;

int main()
{
	int iNumber;
	int iReverse = 0;
	int iCase;
	cin >> iCase;
	while (iCase--)
	{
		while (cin >> iNumber)
		{
			bool bpalindrome = false;
			int counter = 0;
			while (!bpalindrome)
			{

				iReverse = 0;
				int temp = iNumber;
				while (temp)
				{
					iReverse *= 10;
					iReverse += temp % 10;
					temp /= 10;
				}
				if (iNumber == iReverse)
				{
					bpalindrome = true;
					break;
				}
				iNumber += iReverse;
				counter++;
			}
			cout << counter << " " << iNumber << endl;
		}
	}
}