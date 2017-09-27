#include <iostream> 
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

int n, m, k; 

int f[10005][1005];

int tot[10005];

struct Map {
	int up;
	int down;
} map[10005];

struct Conduit{
	bool flag;
	int down;
	int up;
} cons[10005];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 0; i < n; i++)
		scanf("%d%d", &map[i].up, &map[i].down);
	
	int temp;
	
	for (int i = 1; i <= k; i++) {
		scanf("%d", &temp);
		tot[temp]++;
		cons[temp].flag = true;
		scanf("%d%d", &cons[temp].down, &cons[temp].up);
	}
	
	for (int i = 0; i <= n; i++)
		tot[i] += tot[i - 1];
	
	memset(f, -1, sizeof(f));
	
	for (int i = 1; i <= m; i++)
		if (!cons[0].flag || (i > cons[0].down && i < cons[0].up))
			f[0][i] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = map[i - 1].up + 1; j <= m; j++) {
			if (f[i - 1][j - map[i - 1].up] != -1)
				f[i][j] = f[i - 1][j - map[i - 1].up] + 1;
			
			if (f[i][j - map[i - 1].up] != -1) {
				if (f[i][j] == -1)
					f[i][j] = f[i][j - map[i - 1].up] + 1;
				else
					f[i][j] = min(f[i][j], f[i][j - map[i - 1].up] + 1);
			}
		}
		
		if (!cons[i].flag || cons[i].up > m)
			for (int j = max(1, m - map[i - 1].up); j <= m; j++) {
				if (f[i - 1][j] != -1) {
					if (f[i][m] == -1)
						f[i][m] = f[i - 1][j] + 1;
					else
						f[i][m] = min(f[i][m], f[i - 1][j] + 1);
				}
				if (f[i][j] != -1) {
					if (f[i][m] == -1)
						f[i][m] = f[i][j] + 1;
					else
						f[i][m] = min(f[i][m], f[i][j] + 1);
				}
			}
		
		for (int j = 1; j + map[i - 1].down <= m; j++) {
			if (f[i - 1][j + map[i - 1].down] != -1) {
				if (f[i][j] == -1)
					f[i][j] = f[i - 1][j + map[i - 1].down];
				else
					f[i][j] = min(f[i][j], f[i - 1][j + map[i - 1].down]);	
			}
		}
		
		if (cons[i].flag) {
			for (int j = 0; j <= cons[i].down; j++)
				f[i][j] = -1;
			for (int j = cons[i].up; j <= m; j++)
				f[i][j] = -1;
		}
	}
	
	/*
	for (int j = m; j >= 0; j--) {
		for (int i = 0; i <= n; i++)
			cout << setw(3) << f[i][j] << " ";
		cout << endl;
	}
	
	for (int i = 1; i <= n; i++)
		cout << setw(3) << i << " ";
	cout << endl;
	*/
	
	int ans = 999999999;
	
	for (int i = 1; i <= m; i++)
		if (f[n][i] > 0 && f[n][i] < ans)
			ans = f[n][i];
	
	if (ans != 999999999)
		cout << 1 << endl << ans;
	else {
		cout << 0 << endl;
		for (int i = 1; i <= n; i++) {
			bool flg = false;
			
			for (int j = 1; j <= m; j++)
				if (f[i][j] != -1) {
					flg = true;
					break;
				}
			
			if (!flg) {
				cout << tot[i - 1];
				return 0;
			}
		}
	}
		
	return 0;
} 
