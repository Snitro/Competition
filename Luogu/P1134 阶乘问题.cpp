#include<iostream>
#include<cstdio>
using namespace std;
long long n;
int main(){
//	freopen ("in.txt", "r", stdin);
//	freopen ("out.txt", "w", stdout);
	cin >> n;
	long long ans = 1;
	for (long long i = 2; i <= n; i++) {
		long long c = i;
		while ( c % 10 == 0)
			c /= 10;
		c = c % 1000000000;
		ans *= i;
		while(ans % 10 == 0)
			ans /= 10;
		ans = ans % 1000000000;
	}
	cout << ans % 10 ;
	return 0;
}
