#include<iostream>
#include<string>
using namespace std;
int main(){
	int x;
	cin >> x;
	int count = 0;
	int sum=0;
	while (count != x)
	{
		count++;
		int  arr[100];
		int brr[100];
		for (int i = 0; i < x; i++)
		{
			cin >> arr[i];
		}
		int crr[100];
		for (int i = 0; i < x; i++)
		{
			do
			{
				for (int j = 1000000; j>10; j = j / 10)
				{
					if (arr[i] / j != 0)
					{
						brr[i] = arr[i] / j;
						arr[i] = arr[i] % 10;
						crr[i] = brr[i];
					}
				}		
				for (int k = x; x > 0; k--)
				{
					for (int l = 1; l < arr[l-1] / 10; l = l * 10)
						sum += crr[k] * l;
				}
			} while (arr[i] != brr[i]);
			cout << sum << endl;
		}
		system("pause");
	}



}