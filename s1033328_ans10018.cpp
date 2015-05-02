#include<iostream>
#include<string>
using namespace std;
int main(){
	int N,num[2],counter=0,size;
	bool check=true;
	string P;
	cin >> N;
	if (N >= 0 && N <= 100){
		for (int i = 0; i < N; i++){
			cin >> P;
			cout <<  << endl;
			system("pause");
			while (check){
				for (int j = 0; j < sizeof(P) / 2; j++){
					if (P[i] != P[sizeof(P)-j])
						check = false;
				}
				if (check){
					cout << counter<<" "<<P;
				}
				else{
					size = sizeof(P);
					for (int j = 0; j < sizeof(P); j++){
					}
				}
			}

		}
	}
	system("pause");
	return 0;
}