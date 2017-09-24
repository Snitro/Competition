#include <iostream>
#include <cstdio>

#define mod 100000000

using namespace std;

int m, n;

int sit[20];

long long f[20][400];

int init[400];

int init_len;

int main() {
	freopen("in.txt", "r", stdin);
	
	for (int i = 0; i <= 4095; i++) {
		if (i << 1 & i || i >> 1 & i)
			continue;
		init[++init_len] = i;
	}
	
	scanf("%d%d", &m, &n);
	
	int flag;
	
	for (int i = 1; i <= m; i++)
		for (int j = n - 1; j >= 0; j--) {
			scanf("%d", &flag);
			
			if (!flag)
				sit[i] |= (1 << j);
		}
		
	for (int i = 1; i <= init_len && init[i] <= ((1 << n) - 1); i++)
		if (!(init[i] & sit[1]))
			f[1][i] = 1;
			
	for (int i = 2; i <= m; i++)
		for (int j = 1; j <= init_len && init[j] <= ((1 << n) - 1); j++)
			if (!(sit[i] & init[j]))
				for (int k = 1; k <= init_len && init[k] <= ((1 << n) - 1); k++)
					if (!(init[j] & init[k])) {
						f[i][j] += f[i - 1][k];
						f[i][j] %= mod;
					}
	
	long long ans = 0;
	
	for (int i = 1; i <= init_len; i++) {
		ans += f[m][i];
		ans %= mod;
	}
	
	cout << ans;
	
	return 0;
}
