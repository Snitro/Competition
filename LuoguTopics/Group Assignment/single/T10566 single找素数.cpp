#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long a, b;

bool is_prime[300000];//0 ~ ¸ùºÅb 
bool prime[300000];// a ~ b 

void prime_find() {
	for (int i = 2; (long long)i * i <= b; i++) {
		if (is_prime[i]) {
			for (int j = 2 * i; (long long)j * j <= b; j += i)
				is_prime[j] = false;
				
			for (int j = max((long long)2, (a + i - 1) / i) * i; j <= b; j += i)
				prime[j - a + 1] = false;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	memset(is_prime, 1, sizeof(is_prime));
	memset(prime, 1, sizeof(prime));
	
	scanf("%d%d", &a, &b);
	
	prime_find();
	
	long long tot = 0;
	
	for (int i = 1; i <= b - a + 1; i++)
		if (prime[i])
			tot++;
	
	cout << tot;
	
	return 0;
}
