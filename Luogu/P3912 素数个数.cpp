#include <iostream> 
#include <cstdio>

using namespace std;

int prime[10000005], size, n;

bool notPrime[100000005];

void init() {
	if (n >= 2)
		prime[++size] = 2;
	else
		return;
	
	for (register int i = 3; i <= n; i += 2) {
		if (!notPrime[i])
			prime[++size] = i;
		for (register int j = 1; j <= size && prime[j] * i <= n; j++) {
			notPrime[prime[j] * i] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
} 

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	init();
	
	printf("%d", size);
	
	return 0;
}
