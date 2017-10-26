#include <iostream>
#include <cstdio>

#define mod 10000

using namespace std;

int n, k;

int f[1005][1005];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &k);
	
	f[1][0] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			f[i][j] += f[i - 1][j] + f[i][j - 1];
			
			if (j - i >= 0)
				f[i][j] = f[i][j] + mod - f[i - 1][j - i];
				
			f[i][j] %= mod;
		}
	}
	
	cout << f[n][k];
	
	return 0;
}
