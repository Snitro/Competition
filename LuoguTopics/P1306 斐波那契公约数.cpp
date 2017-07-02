#include <iostream>
#include <cstdio>

#define mod 100000000

using namespace std;

long long n,m;

long long F[10000000];

long long gcd(long long a, long long b) {
	long long c = 1;
	while (c != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void get(long long id) {
	if (F[id])
		return;
	if (id % 2) {
		long long x = id / 2;
		get(x);
		get(x + 1);
		F[id] = ((F[x] * F[x]) % mod) + ((F[x + 1] * F[x + 1]) % mod);
		F[id] = F[id] % mod;
	} else {
		long long x = id / 2;
		get(x);
		get(x - 1);
		F[id] = (((2 * F[x - 1]) % mod + F[x]) % mod) * F[x];
		F[id] = F[id] % mod;
	}
	
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	n = gcd(n, m);
	F[1] = F[2] = 1;
	get(n);
	cout << F[n];
}
