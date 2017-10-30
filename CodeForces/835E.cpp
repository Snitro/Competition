#include <iostream>
#include <cstdio>

using namespace std;

int n, x, y, ans1, query[20][1005];

int main() {
	scanf("%d%d%d", &n, &x, &y);
	
	for (int i = 0; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (j & (1 << i))
				query[i][++query[i][0]] = j;
		
		printf("? %d ", query[i][0]);
		
		for (int j = 1; j <= query[i][0]; j++)
			printf("%d ", query[i][j]);
			
		printf("\n");
		fflush(stdout);
		
		cin >> query[i][query[i][0] + 1];
	}
	
	for (int i = 0; (1 << i) <= n; i++) {
		if (query[i][query[i][0] + 1] == (x ^ y) || query[i][query[i][0] + 1] == y) {
			int l = 1, r = query[i][0], m, ret;
			
			while (l < r) {
				m = (l + r) >> 1;
				
				printf("? %d ", m - l + 1);
				
				for (int j = l; j <= m; j++)
					printf("%d ", query[i][j]);
				
				printf("\n");
				fflush(stdout);
				
				cin >> ret;
				
				if (ret == (x ^ y) || ret == y)
					r = m;
				else 
					l = m + 1;
			}
			
			ans1 = query[i][l];
			
			int bit = 0;
			
			for (int j = 0; (1 << j) <= n; j++)
				if (query[j][query[j][0] + 1] == (x ^ y) || query[j][query[j][0] + 1] == y)
					bit |= (1 << j);
			
			printf("! %d %d", min(ans1, ans1 ^ bit), max(ans1, ans1 ^ bit));
			
			return 0;
		}
	}
	
	return 0;
}
