#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,k,x;
ll GCD(ll a,ll b){
	ll c;
	while(c != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
ll getGB(ll a,ll b){
	ll c = GCD(a,b);
	return a / c;
}
ll ksm(ll a,ll b,ll mo){
	if(b == 0)
		return 1;
	if(b == 1)
		return a % mo;
	ll c = ksm(a,b / 2,mo) % mo;
	if(b % 2 == 0)
		return c * c % mo;
	else
		return ((c * c) % mo) * (a % mo) % mo;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m >> k >> x;
	m = m % n;
	ll mo = getGB(n,m);
	ll s = ksm(10 % mo,k,mo);
	s = s % n;
	cout << ((s * m) % n + x) % n;
	return 0;
}
