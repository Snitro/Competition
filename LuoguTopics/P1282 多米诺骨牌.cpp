#include <iostream>
#include <cstdio>
#include <cstring>

#define abs(x) ((x) > 0 ? (x) : (-(x)))

using namespace std;

int n;

int datas[1005];

int f[1005][10005];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	int a, b;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		datas[i] = a - b;
	}
	
	memset(f, 0x7f7f7f, sizeof(f));
	
	f[1][datas[1] + 5000] = 0;
	f[1][5000 - datas[1]] = 1;
	
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 10000; j++) {
			f[i][j + datas[i]] = min(f[i][j + datas[i]], f[i - 1][j]);
			f[i][j - datas[i]] = min(f[i][j - datas[i]], f[i - 1][j] + 1);
		}
	
	for (int i = 5000; i <= 10000; i++)
		if (f[n][i] < f[0][0] || f[n][5000 - (i - 5000)] < f[0][0]) {
			cout << min(f[n][i], f[n][5000 - (i - 5000)]);
			return 0;
		}
	
	return 0;
}
