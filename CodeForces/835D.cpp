#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[5005][5005], ans[20];

char s[5005];

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%s", s + 1);
	
	for (int i = 1; i <= (int)strlen(s + 1); i++) {
		f[i][i] = 1;
		ans[1]++;
	}
	
	for (int k = 1; k <= (int)strlen(s + 1); k++) {
		for (int i = 1; i + k <= (int)strlen(s + 1); i++) {
			if (s[i] == s[i + k] && (k == 1 || f[i + 1][i + k - 1])) {
				f[i][i + k] = 1 + min(f[i][i + (k - 1) / 2], f[i + (k - 1) / 2 + 1 + (k % 2 ? 0 : 1)][i + k]);
				
				for (int j = 1; j <= f[i][i + k]; j++)
					ans[j]++;
			}
		}
	}
	
	for (int i = 1; i <= (int)strlen(s + 1); i++)
		printf("%d ", ans[i]);
			
	return 0;
}
