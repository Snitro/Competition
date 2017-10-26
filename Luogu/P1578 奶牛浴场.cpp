#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int l, w, n;

long long ans = 0;

int up, down;

struct Node {
	int x;
	int y;
} nodes[5005];

bool cmp(Node a, Node b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y > b.y;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &l, &w, &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &nodes[i].x, &nodes[i].y);
	
	nodes[++n].x = l;
	nodes[n].y = w;
    nodes[++n].x = l;
	nodes[n].y = 0;
    nodes[++n].x = 0;
	nodes[n].y = w;
	nodes[++n].x = 0;
	nodes[n].y = 0;
	
	sort(nodes + 1, nodes + 1 + n, cmp);
	
	for (int i = 1; i <= n; i++) {
		up = 0;
		down = w;
		
		for (int j = i + 1; j <= n; j++) {
			ans = max(ans, (long long)(down - up) * (nodes[j].x - nodes[i].x));
			if (nodes[j].y > nodes[i].y)
				down = min(nodes[j].y, down);
			else if (nodes[j].y < nodes[i].y)
				up = max(up, nodes[j].y);
			else 
				break;
		}
	}
	
	cout << ans;
	
	return 0;
}
