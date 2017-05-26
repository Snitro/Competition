#include<iostream>
using namespace std;
int n;
int ans = 999999999;
int main(){
	cin >> n;
	int a,b;
	for(int i = 1;i <= 3;i++){
		cin >> a >> b;
		int k = n / a;
		if(n % a)
			k++;
		ans = min(ans,k * b);
	}
	cout << ans;
}
