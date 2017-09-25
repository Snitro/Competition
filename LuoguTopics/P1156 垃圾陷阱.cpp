#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int d, n;

int f[105][105];

struct Node {
	int t;
	int x;
	int h;
} nodes[105];

bool cmp(Node a, Node b) {
	return a.t < b.t;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &d, &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &nodes[i].t, &nodes[i].x, &nodes[i].h);
		
	sort(nodes + 1, nodes + 1 + n, cmp);
	
	f[0][0] = 10;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= d; j++) {
			if (f[i][j] < nodes[i + 1].t)
				continue;
				
			int x = j + nodes[i + 1].h;
			
			if (x >= d) {
				cout << nodes[i + 1].t;
				return 0;
			}
			
			f[i + 1][j] = max(f[i + 1][j], f[i][j] + nodes[i + 1].x);
			f[i + 1][x] = max(f[i + 1][x], f[i][j]);
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i][0]);
	
	cout << ans;
	
	return 0;
}
