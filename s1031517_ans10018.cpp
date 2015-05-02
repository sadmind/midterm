#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
// find size(ip, size)  reverse(ip , size)  add  pld
void cha(int , int &);

int main()
{
	string sp[100];
	stringstream spn[100];
	int in;
	int ip[100];
	int arip[100][100];
	int size[100] = { 0 };

	ifstream data("data_uva10018.txt", ios::in);
	data >> in;
	for (int i = 0; i < in; i++)
	{
		data >> sp[i];
		spn[i] << sp[i];
		spn[i] >> ip[i];
		//cout << ip[i] << endl;  // 195
		cha(ip[i], size[i]);
		//cout << size[i];  //  3
		int time = 0;
		bool pa = false;
		int a = 10; 
		for (int j = 0; j < size[i]; j++)
		{
			int b = ip[i] % a;  // 5 
			ip[i] /= 10; // 19  
			arip[i][j] = b;  //  5
		}
				
		while (pa == false)
		{
			// reverse
			int cparip[100][100];
			for (int k = 0; k < size[i]; k++)
				cparip[i][k] = arip[i][k];

			int c;
			if (size[i] % 2 == 0)
				c = size[i] / 2; // 4 // 2  // 3 2 1 0
			else
				c = (size[i] - 1) / 2;  // 3 5 // 1 2 // 432 1 0
			for (int s = 0; s < c; s++)
			{
				int d = arip[i][s];
				arip[i][s] = arip[i][size[i] - 1 - s];
				arip[i][size[i] - 1 - s] = d;
			}

			//add
			int add[100][100];
			for (int q = 0; q < size[i]; q++)
			{
				add[i][q] = 0;
				add[i][q] = cparip[i][q] + arip[i][q];
			}
			for (int q = 0; q < size[i]; q++)
			{
				if (add[i][q] >= 10)
				{
					add[i][q + 1]++;
					add[i][q] %= 10;
				}				
			}
			if (add[i][size[i]] != 0)
				size[i]++;

			//pa
			pa = false;
			int e;
			if (size[i] % 2 == 0)
				e = size[i] / 2; // 4 // 2
			else
				e = (size[i] - 1) / 2;  // 3  // 1
			for (int q = 0; q < e; q++)
			{
				if (add[i][q] != add[i][size[i] - q - 1])
					break;
				else
				{
					if (q == e - 1)
						pa = true;
				}
			}
			for (int q = 0; q < size[i]; q++)
				arip[i][q] = add[i][q];

			time++;

		} 

		cout << time << "  " << endl;

		for (int k = 0; k < size[i]; k++)
			cout << arip[i][k];

		cout << endl;
		
	}
	

	system("pause");
}

void cha(int b, int &size)
{
	int a = 10;
	int c;
	for (int i = 1; i > 0; i++)
	{
		c = b % a;
		a *= 10;
		size = i;
		if (c == b)
			break;
	}
}

