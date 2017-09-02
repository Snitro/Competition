#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

struct Node {
	int l;
	int r;
} nodes[50005];

bool cmp(Node a, Node b) {
	if (a.l == b.l)
		return a.r < b.r;
		
	return a.l < b.l;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &nodes[i].l, &nodes[i].r);
	
	n++;
	nodes[n].l = nodes[n].r = 1000001;
	
	sort(nodes + 1, nodes + 1 + n, cmp);
	
	for (int i = 2; i <= n; i++) {
		if (nodes[i - 1].l <= nodes[i].l && nodes[i - 1].r >= nodes[i].l) {
			nodes[i].l = min(nodes[i].l, nodes[i - 1].l);
			nodes[i].r = max(nodes[i].r, nodes[i - 1].r);
		} else {
			printf("%d %d\n", nodes[i - 1].l, nodes[i - 1].r);
		}
	}
	
	return 0;
}
