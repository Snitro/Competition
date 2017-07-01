/*
F[2n] = F[n+1]^2 - F[n-1]^2 = (2F[n-1] + F[n]) ¡¤ F[n]

F[2n+1] = F[n+1]^2 + F[n]^2
*/

#include <iostream>
#include <cstdio>
#include <map>

#define mod 1000000007

using namespace std;

map <long long,long long> F;

long long n;

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
	freopen("out.txt", "w", stdout);
	cin >> n;
	F[1] = 1;
	F[2] = 1;
	get(n);
	cout << (F[n] % mod);
	return 0;
}
