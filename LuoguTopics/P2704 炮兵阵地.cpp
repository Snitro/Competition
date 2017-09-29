#include <iostream> 
#include <cstdio>

using namespace std;

int n, m;

int f[105][100][100];

int init[100], count[100], len;

int map[105];

int Count(int a) {
	int ret = 0;
	
	for (int i = 0; (1 << i) <= a; i++)
		if (a & (1 << i))
			ret++;
	
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	char temp[20];
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", temp);
		
		for (int j = 0; j < m; j++) {
			map[i] = map[i] << 1;
			
			if (temp[j] == 'H')
				map[i] |= 1;
		}
	}
	
	for (int i = 0; i < (1 << m); i++)  {
		if ((i << 1) & i || (i << 2) & i)
			continue;
		
		init[++len] = i;
		count[len] = Count(i);
	}
	
	for (int i = 1; i <= len; i++)
		if (!(map[1] & init[i]))
			f[1][1][i] = count[i];
	
	for (int i = 1; i <= len; i++)
		for (int j = 1; j <= len; j++)
			if (!(init[i] & init[j]) && !(map[1] & init[j]) && !(map[2] & init[i]))
				f[2][j][i] = count[i] + count[j];
	
	int ans = 0;
	
	for (int i = 3; i <= n; i++)
		for (int j = 1; j <= len; j++)
			if (!(map[i] & init[j]))
				for (int k = 1; k <= len; k++)
					if (!(init[j] & init[k]) && !(init[k] & map[i - 1]))
						for (int l = 1; l <= len; l++)
							if (!(init[l] & init[j]) && !(init[l] & init[k]) && !(map[i - 2] & init[l]))
								f[i][k][j] = max(f[i][k][j], f[i - 1][l][k] + count[j]);
								
	for (int i = 1; i <= len; i++)
		for (int j = 1; j <= len; j++)
			ans = max(ans, f[n][i][j]);
					
	cout << ans;
	
	return 0;
}
