#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>Array;
	int digits,times=0;
	cin >> digits;
	for (int i = 1; i <= digits; i++)
	{
		cin >> Array[i];
	}
	do
	{
		for (int i = 1; i <= Array.size(); i++)
		{
			Array[i] = Array[i] + Array[Array.size()];
			if (Array[i] >= 10)
			{
				Array[i + 1] = Array[i+1] + 1;
				Array[i] = Array[i] % 10;
			}

		}
		if (Array.size() % 2 == 0)
		{
			for (int i = 1; i <= Array.size() / 2; i++)
			{
				if (Array[i] == Array[Array.size() - i + 1])
				{
					times = 1;
				}
				

			}
		}
		if (Array.size() % 2 == 1)
		{
			for (int i = 1; i <= Array.size() / 2; i++)
			{
				if (Array[i] == Array[Array.size() - i + 1])
				{
					times = 1;
				}


			}
		}
	} while (times != 1);
	system("pause");
	return 0;



}