#include <iostream>

using namespace std;

long long ans[25][25], n, m, a, b;

int main() {
	cin >> n >> m >> a >> b;
	
	ans[a][b] = -1;
	ans[0][0] = 1;
	if (a - 1 >= 0 && b - 2 >= 0)
		ans[a - 1][b - 2] = -1;
	if (a - 1 >= 0 && b + 2 >= 0)
		ans[a - 1][b + 2] = -1;
	if (a + 1 >= 0 && b - 2 >= 0)
		ans[a + 1][b - 2] = -1;
	if (a + 1 >= 0 && b + 2 >= 0)
		ans[a + 1][b + 2] = -1;
	if (a + 2 >= 0 && b + 1 >= 0)
		ans[a + 2][b + 1] = -1;
	if (a + 2 >= 0 && b - 1 >= 0)
		ans[a + 2][b - 1] = -1;
	if (a - 2 >= 0 && b - 1 >= 0)
		ans[a - 2][b - 1] = -1;
	if (a - 2 >= 0 && b + 1 >= 0)
		ans[a - 2][b + 1] = -1;
	
	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= n; j++) {
			if (i == j && i == 0 || ans[j][i] == -1)
				continue;
			if (j - 1 >= 0 && ans[j - 1][i] != -1)
				ans[j][i] += ans[j - 1][i];
			if (i - 1 >= 0 && ans[j][i - 1] != -1)
				ans[j][i] += ans[j][i - 1];
		}
		
	cout << (ans[n][m] == -1 ? 0 : ans[n][m]);
	
	return 0;
}
