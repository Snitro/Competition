#include<iostream>
#include<cstdio>
using namespace std;
int n;
int f[50];
bool judge(int n){
	for(int i = 2;i <= n / 2;i++)
		if(n % i == 0)
			return false;
	return true;
}
void dec(int n){
	cout << n << "=";
	while(true){
		for(int i = 2;;i++){
			if(judge(n)){
				cout << n;
				return;	
			}else if(judge(i)){
				while(n / i * i == n){
					n /= i;
					cout << i;
					if(n != 1)
						cout << "*";
					else 
						return;
				}
			}
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	f[1] = f[2] = 1;
	for(int i = 3;i < 50;i++){
		f[i] = f[i - 1] + f[i - 2];
		f[i] %=  2147483648;
	}
	dec(f[n]);
}
