#include <iostream>
#include <cstdio>

using namespace std;

long long f[100005];

int cost[10], num[10], tot, s;

int main() {
	freopen("in.txt", "r", stdin);
	
	for (int i = 1; i <= 4; i++)
		scanf("%d", &cost[i]);
	
	scanf("%d", &tot);
	
	f[0] = 1;
	
	for (int i = 1; i <= 4; i++)
		for (int j = cost[i]; j <= 100000; j++)
			f[j] += f[j - cost[i]];
			
	while (tot--) {
		for (int i = 1; i <= 4; i++)
			scanf("%d", &num[i]);
			
		scanf("%d", &s);
		
		long long ans = 0;
		int c, t;
		
		for (int i = 0; i <= 15; i++) {
			t = s;
			c = 0;
			
			for (int j = 0; j < 4; j++)
				if (i & (1 << j)) {
					c++;
					t -= (num[j + 1] + 1) * cost[j + 1];
				}
			
			if (t < 0) 
				continue;
			
			if (c % 2)
				ans -= f[t];
			else
				ans += f[t];
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
