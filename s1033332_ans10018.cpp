#include<iostream>
using namespace std;

int main()
{
	int key;

	int a[10];
	int save2[10] = {};
	int sum[10] = {};
	cin >> key;
	int j = 1;
	int c = 1;
	for (int i = 0; i < key; i++)
	{
		cin >> a[i];
		int temp = a[i];
		while (temp>0)
		{
			save2[j] = temp % 10;
			temp /= 10;
			j++;
		}
		j--;
		int k = j;

		for (int q = 0; q<4; q++)
		{
			for (int i = 1; i <= k; i++)
			{
				sum[i] = save2[i] + save2[j];
				j--;
				if (sum[i] > 10)
				{
					sum[i - 1] += 1;
					sum[i] -= 10;
				}
			}
			if (sum[0] != 0)
			{
				for (int i = k; i >= 0; i--)
				{
					sum[i+1] = sum[i];
				}
				k++;
				sum[0] = 0;
			}
			j = k;

			for (int i = 1; i <= k; i++)
			{
				save2[i] = sum[i];
			}
			j = k;
		}
		for (int i = 1; i <= k; i++)
			cout << sum[i];
		cout << endl;
	}


	system("pause");
	return 0;
}