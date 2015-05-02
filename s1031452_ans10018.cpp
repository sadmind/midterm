#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void inttoarray(vector<int>&a, int b)
{
	int count = 1;
	int tmp = b;
	while (1)
	{
		a.push_back(tmp % 10);
		tmp =tmp / 10;
		if (tmp / 10 == 0)
		{
			a.push_back(tmp);
			break;
		}
	}
}
int arraytoint(vector<int>a)
{
	int num = 0;
	int length = a.size();
	for (int i = 0; i < length; i++)
	{
		num = num * 10;
		num += a[i];
	}
	return num;
}
void reverse(vector<int>a, vector<int>&b)
{
	int len = a.size();
	b.resize(len);
	for (int i = 0; i < len; i++)
		b[i] = a[len - 1 - i];
}
bool compare(vector<int>a, vector<int>b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]!=b[i])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int N;
	cin >> N;
	vector<int>number;
	vector<int>result;
	number.resize(N);
	result.resize(N);
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		int test;
		cin >> test;
		vector<int>num;
		inttoarray(num, test);
		vector<int>re;
		reverse(num, re);
		while (compare(num,re))
		{
			vector<int>sum(num.size() + 1);
			for (int j = 0; j < sum.size(); j++)
				sum[j] = 0;
			int length = sum.size();
			for (int j = 0; j <num.size(); j++)
			{
				sum[j] = num[j] + re[j];
			}
			for (int j = 0; j < sum.size()-1;j++)
			{
				if (sum[j] >= 10)
				{
					sum[j + 1] += (sum[j] / 10);
					sum[j] = sum[j] % 10;
				}
			}
			if (sum[length - 1] == 0)
				length--;
			
			num.resize(length);
			for (int j = 0; j < length; j++)
			{
				num[j] = sum[j];
			}
			reverse(num, re);
			count++;
		}
		number[i] = count;
		result[i] = arraytoint(num);
	}
	for (int i = 0; i <N; i++)
	{
		cout << number[i] << " " << result[i] << endl;
	}
	system("pause");
	return 0;
}