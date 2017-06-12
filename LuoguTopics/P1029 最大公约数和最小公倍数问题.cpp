#include<iostream>
#include<cstdio>
using namespace std;
long long a,b;
long long gcd(long long a,long long b){
	long long c = 1;
	while(c != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> a >> b;
	int ans = 0;
	for(int i = 1;a * i <= b;i++){
		long long c = a * i;
		long long d = a * b / c;
		if(a * b % c != 0)
			continue;
		if(gcd(c,d) == a)
			ans++;
	}
	cout << ans;
	return 0;
}
