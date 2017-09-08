#include <iostream>
#include <cstdio>

using namespace std;

int n;

int to[200005];

int clk[200005];
int clock;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &to[i]);
	
	int ans = 999999999;
	
	for (int i = 1; i <= n; i++)
		if (!clk[i]) {
			int start = ++clock;
			
			int j = i;
			
			while (!clk[j]) {
				clk[j] = ++clock;
				j = to[j];
			}
			
			if (clk[j] >= start && clock - clk[j] + 1 < ans)
				ans = clock - clk[j] + 1;
		}
	
	cout << ans;
	
	return 0;
}
