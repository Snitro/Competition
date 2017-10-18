#include <iostream>
#include <cstdio>
#include <cmath>

#define max(a, b) ((a) >= (b) ? (a) : (b))

using namespace std;

int n, m;

int f[100005][25];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i][0]);
		
	for (int i = 1; (1 << i) <= n; i++)
		for (int j = 1; j + (1 << (i - 1)) <= n; j++)
			f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
	
	int a, b, c;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		
		c = log2(b - a + 1);
		
		printf("%d\n", max(f[a][c], f[b - (1 << c) + 1][c]));
	}
	
	return 0;
}
