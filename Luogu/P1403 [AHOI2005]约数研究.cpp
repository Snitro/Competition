#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int ans = 0,n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		ans += n / i;
	cout << ans;
}
