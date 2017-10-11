#include <iostream>
#include <cstdio>

#define mod 100003

using namespace std;

long long pow(long long a, long long b) {
	long long ret = 1;
	
	for (; b; b >>= 1) {
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
	}
	
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	long long n, m;
	
	scanf("%lld%lld", &m, &n);
	
	printf("%lld", (pow(m, n) - (m * pow(m - 1, n - 1) % mod) + mod) % mod);
	
	return 0;
}
