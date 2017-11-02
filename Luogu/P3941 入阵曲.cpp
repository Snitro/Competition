#include <iostream>
#include <cstdio>
#include <cstring>

#define lowbit(x) ((x) & (-x))

using namespace std;

long long ans = 0;

int datas[405][405], n, m, k;

int sum[405][405], tot[1000005], temp[405];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &datas[i][j]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = (sum[i - 1][j] + datas[i][j]) % k;

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			tot[0] = 1;
			
			for (int l = 1; l <= m; l++) {
				temp[l] = (temp[l - 1] + sum[j][l] - sum[i - 1][l]) % k;
				if (temp[l] < 0)
					temp[l] += k;
				ans += tot[temp[l]];
				tot[temp[l]]++;
			}
			
			for (int l = 1; l <= m; l++)
				tot[temp[l]] = 0;
		}
	
	cout << ans;
	
	return 0;
}
