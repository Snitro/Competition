#include <iostream>
#include <cstdio>

using namespace std;

int n;

long long k;

int pow[505];

int main() {
	scanf("%d%I64d", &n, &k);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &pow[i]);

	int MAX = pow[1], num = 0;

	for (int i = 2; i <= n && num < k; i++) {
		if (pow[i] < MAX)
			num++;
		else {
			MAX = pow[i];
			num = 1;
		}
	}
	
	printf("%d", MAX);
		
	return 0;
}
