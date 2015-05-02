#include<iostream>
#include<string>

using namespace std;
void putin(int);
void compute();
void compare();
int _array[100][20];
int input;
int n;
int time=0;
int value = -1;
int main()
{
	cin >> n;
	while (time < n)
	{
		cin >> input;
		putin(input);
		compute();
		time++;
	}
	
	system("pause");
}

void putin(int input)
{
	int i=10;
	value = -1;
	do
	{
		i=i * 10;
		value++;
	} while (i < input/10);
	cout << i << endl;
	int j=value+2;
	while (i>=1)
	{
		_array[time][j]=input / i;
		input = input - _array[time][j] * i;
		i=i / 10;
		j--;
		
	}
	//for (int p = 3; p>=0; p--)
		//cout<<_array[time][p];
}

void compute()
{
	int x;
	int y;
	x = time;
	y = value+2;
	int a=0;
	int temp[100][20];
	while (y>=0)
	{
		 
		 temp[x][a] = _array[x][a]+_array[x][y];
		 y--;
		 
		 a++;
		 
	}
	 //cout << _array[x][3] << endl;
	 int i = 0;
	 while (i<=value+2)
	 {
		 if (temp[x][i] >= 10)
		 {
			 temp[x][i + 1] = temp[x][i+1] + temp[x][i] / 10;
			 temp[x][i] = temp[x][i] % 10;
		 }
		 i++;
	 }
	 for (int j = 0; j <= 20; j++)
		 _array[x][j] = temp[x][j];
}

void compare()
{
	
}