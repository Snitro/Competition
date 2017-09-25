#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int a_len, a[505], pos[505], b_len, b[505];

int f[505][505];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	while (n--) {
		memset(f, 0, sizeof(f));
		
		scanf("%d", &a_len);
		
		for (int i = 1; i <= a_len; i++) {
			scanf("%d", &a[i]);
			pos[i] = i;
		}
		
		scanf("%d", &b_len);
		
		for (int i = 1; i <= b_len; i++)
			scanf("%d", &b[i]);
		
		int ans = 0;	
		
		for (int i = 1; i <= a_len; i++) {
			int MAX = 0;
			 
			for (int j = 1; j <= b_len; j++) {
				if (a[i] > b[j])
					MAX = max(MAX, f[i - 1][j]);
				
				if (a[i] == b[j])
					f[i][j] = MAX + 1;
				else
					f[i][j] = f[i - 1][j];
			}
		}
		
		for (int i = 1; i <= b_len; i++)
			ans = max(ans, f[a_len][i]);
		
		printf("%d\n", ans);
	}
	
	return 0;
}
