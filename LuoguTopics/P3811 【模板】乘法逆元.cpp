#include <iostream>
#include <cstdio>

using namespace std;

int Div[3000005];

int ans[3000005];

int n, p;

bool isprime[3000005];

int prime_list[3000005], size;

void init() {
	for (int i = 2; i <= n; i++) {
		if (!isprime[i])
			prime_list[++size] = i;
		for (int j = 1; prime_list[j] * i <= n && j <= size; j++) {
			Div[prime_list[j] * i] = i;
			isprime[prime_list[j] * i] = true;
			if (i % prime_list[j] == 0)
				break;
		}
	}
}

void ex_gcd(int a, int b, int & x, int & y) {
	if (b == 0) {
		x = 1;
		y = 0;
	} else {
		ex_gcd(b, a % b, y, x);
		y -= x * (a / b);
	}
}

int inv(int a, int b) {
	if (Div[a]) {
		ans[a] = ans[Div[a]] * (long long)ans[a / Div[a]] % b;
		return ans[Div[a]] * (long long)ans[a / Div[a]] % b;
	}
	
	
	int x, y;
	ex_gcd(a, b, x, y);
	ans[a] = ((x % b) + b) % b;
	return ((x % b) + b) % b;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &p);
	
	init();
	
	for (int i = 1; i <= n; i++)
		printf("%d\n", inv(i, p));
	
	return 0;
}
