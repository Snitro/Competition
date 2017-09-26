#include <iostream> 
#include <cstdio>

using namespace std;

int init[200], tot[200], init_len;

int n, K;

long long f[10][100][200];

int count(int x) {
	int ret = 0;
	
	for (int i = 0; (1 << i) <= x; i++)
		if (x & (1 << i))
			ret++;
	
	return ret;
}

bool judge(int a, int b) {
	if ((a & b) || ((a << 1) & b) || ((a >> 1) & b))
		return false;
		
	return true;
}

void dfs(int cond, int sum, int pos) {
	if (pos > n) {
		init[++init_len] = cond;
		tot[init_len] = sum;
		return;
	}
	
	dfs(cond + (1 << (pos - 1)), sum + 1, pos + 2);
	dfs(cond, sum, pos + 1);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &K);
	
	dfs(0,0,1);

	for (int i = 1; i <= init_len; i++)
		f[1][i][tot[i]] = 1;
	
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= init_len; j++)
			for (int k = 1; k <= init_len; k++)
				if (judge(init[j], init[k]))
					for (int sum = tot[j]; sum <= K; sum++)
						f[i][j][sum] += f[i -1][k][sum - tot[j]];
	
	long long ans = 0;
	
	for (int i = 1; i <= init_len; i++)
		ans += f[n][i][K];
	
	cout << ans;
	
	return 0;
}
