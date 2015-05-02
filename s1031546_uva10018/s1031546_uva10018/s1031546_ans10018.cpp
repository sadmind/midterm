#include <iostream>

using namespace std;

int main()
{
	int key = 0, *ans , *num ,*size, temp , temp1 , temp2 , temp3;
	cin >> key;
	ans = new int[key];
	num = new int[key];
	size = new int[key];
	for (int i = 0; i < key; i++)
	{
		cin >> ans[i];
		num[i] = 0;
		temp = 1;
		for (int k = 0; ans[i] / temp != 0; k++)
		{
			temp = temp * 10;
			num[i] = k ;
		}
		num[i] = num[i] + 1;
		size[i] = temp / 10;
	}
	cout << endl;
	for (int i = 0; i < key; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp1 = 1;
			temp2 = 0;
			temp3 = ans[i];
			for (int k = 0; k < num[i]; k++)
			{
				temp2 = (temp3 / size[i])*temp1 + temp2;
				temp3 = temp3 % size[i];
				size[i] = size[i] / 10;
				temp1 = temp1 * 10;
				if (size[i] == 0)
					size[i] = 1;
			}
			ans[i] = ans[i] + temp2;
			temp = 1;
			for (int k = 0; ans[i] / temp != 0; k++)
			{
				temp = temp * 10;
				num[i] = k;
			}
			num[i] = num[i] + 1;
			size[i] = temp / 10;
			
		}
		cout << num[i] << " " << ans[i] << endl;
	}


	system("pause");
	return 0;
}