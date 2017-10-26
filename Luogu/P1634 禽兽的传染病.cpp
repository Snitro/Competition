#include<iostream>
using namespace std;
long long end = 1;
int x,n;
int main(){
	cin >> x >> n;
	for(int i = 1;i <= n;i++){
		end += end * x;
	}
	cout << end;
}
