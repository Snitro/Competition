#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int save[100005];

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d", &n, &m);

	if (n == 2 && m == 0) {
		puts("NO");
		return 0;
	}
	
	puts("YES");
	
	if (n <= 3) {
		if (n == 1) {
			cout << m << endl;
			return 0;
		} else if (n == 2) {
			cout << 0 << " " << m << endl;
			return 0;
		} else if (n == 3) {
			int k;
			for (int i = 0; i <= 1000000; i++)
				for (int j = 0; j <= 1000000; j++) {
					if (i == j)
						continue;
					k = i ^ j;
					if ((m ^ k) != i && (m ^ k) != j) {
						cout << i << " " << j << " " << (m ^ k);
						return 0;
					}
				}
		}
		
		puts("NO");
		
		return 0;
	}
	
	long long ans = 0, tot = 0;
	
	for (int i = 1; tot < n - 3; i++) {
		if (i != m) {
			if (tot + 1 == n - 3 && (ans ^ i) == 0) // importa 
				continue;
			ans ^= i;
			save[++tot] = i;
		}
	}
	
	for (int i = save[tot] + 1; i <= 1000000; i++) {
		if ((ans ^ i) > save[tot] && i != m && (ans ^ i) != m && i != (ans ^ i)) {
			for (int i = 1; i <= tot; i++)
				printf("%d ", save[i]);
				
			printf("%d %I64d %d", i, ans ^ i, m);
			return 0;
		}
	}
	
	return 0;
}
