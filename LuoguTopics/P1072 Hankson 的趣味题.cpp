#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

long long a, b, c, d;

int A[45005], B[45005], C[45005], D[45005];

int prime[100001], size;

bool notPrime[100001];

int analyse (int * map, long long num) {
	for (int i = 1; i <= size && num > 1; i++) {
		while (num % prime[i] == 0) {
			map[i]++;
			num /= prime[i];
		}
	}
	if (num > 1) {
		prime[++size] = num;
		map[size] = 1;
		return 1;
	}
	return 0;
} 

void init() {
	for (int i = 2; i <= 50000; i++) {
		if (!notPrime[i])
			prime[++size] = i;
		for (int j = 1; j <= size && prime[j] * i <= 50000; j++) {
			notPrime[prime[j] * i] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

void solve() {
	int tot = 0;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	if(b > a || d < c)  {
		printf("0\n");
		return;
	}
	long long ans = 1;
	
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(C, 0, sizeof(C));
	memset(D, 0, sizeof(D));
	
	tot += analyse(B, b);
	tot += analyse(A, a);
	tot += analyse(C, c);
	tot += analyse(D, d);
	
	for (int i = 1; i <= size; i++) {
		bool flag = false;
		
		if (D[i] == C[i] && A[i] == B[i])
			ans *= (D[i] - B[i] + 1);
		
		if (A[i] != B[i])
			if (D[i] != C[i])
				flag = D[i] != B[i];
			if (D[i] == C[i])
				flag = B[i] > D[i];
		
		if (C[i] != D[i])
			if (A[i] != B[i])
				flag = D[i] != B[i];
			if (A[i] == B[i])
				flag = D[i] < B[i];
		
		if (flag) {
			printf("0\n");
			return;
		}
		
	}
	
	printf("%lld\n", ans);
	
	size -= tot;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	init();
	
	int n;
	
	scanf("%d", &n);
	
	while (n--)
		solve();
	
	return 0;
}
