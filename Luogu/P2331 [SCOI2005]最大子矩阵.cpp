#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, k;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &k);
	
	if (m == 1) {
		int data, f[105][20][2];
		
		memset(f, 0, sizeof(f));
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &data);
			
			for (int j = 1; j <= k; j++) {
				f[i][j][1] = max(f[i - 1][j][1] + data, f[i - 1][j - 1][0] + data);
				f[i][j][0] = max(f[i - 1][j][1], f[i - 1][j][0]);
			}
		}
		
		cout << max(f[n][k][0], f[n][k][1]);
	} else {
		int datas[105][2], f[105][20][5];
		
		memset(f, -0x7f, sizeof(f));
		
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				f[i][j][0] = 0;
		
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &datas[i][0], &datas[i][1]);
			
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++) {
				f[i][j][0] = max(f[i - 1][j][0], max(f[i - 1][j][1], max(f[i - 1][j][2], max(f[i - 1][j][3], f[i - 1][j][4]))));
				f[i][j][1] = max(f[i][j - 1][0], max(f[i - 1][j][3], f[i - 1][j][1])) + datas[i][0];
				f[i][j][2] = max(f[i][j - 1][0], max(f[i - 1][j][3], f[i - 1][j][2])) + datas[i][1];
				f[i][j][3] = max(f[i - 1][j - 1][1], max(f[i - 1][j - 1][2], f[i - 1][j][3])) + datas[i][0] + datas[i][1];
				
				if (j >= 2)
					f[i][j][3] = max(f[i][j][3], f[i][j - 2][0] + datas[i][1] + datas[i][0]);
				
				f[i][j][4] = max(f[i][j - 1][0], f[i - 1][j][4]) + datas[i][0] + datas[i][1];
			}
		
		cout << max(f[n][k][0], max(f[n][k][1], max(f[n][k][2], max(f[n][k][3], f[n][k][4]))));
	}
	
	return 0;
}
