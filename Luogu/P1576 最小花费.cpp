#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, m;

int head[2005];

bool flg[2005];

double ans[2005];

struct Edge {
	int to;
	int next;
	int value;
} edges[4000005];

int edge_len = 0;

queue <int> Q;

void add(int from, int to, int value) {
	edge_len++;
	
	edges[edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int x, y, z;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	
	cin >> x >> y;
	
	for (int i = 1; i <= n; i++)
		ans[i] = 999999999999999;
		
	Q.push(y);
	flg[y] = true;
	ans[y] = 100;

	while (Q.size()) {
		int from = Q.front();
		Q.pop();
		flg[from] = false;
		
		for (int i = head[from]; i != 0; i = edges[i].next) {
			Edge &edge = edges[i];
			
			if (ans[from] / (1 - (double)edge.value / 100) < ans[edge.to]) {
				ans[edge.to] = ans[from] / (1 - (double)edge.value / 100);
				
				if (!flg[edge.to]) {
					flg[edge.to] = true;
					Q.push(edge.to);
				}
			}
		}
	}
	
	printf("%.8f", ans[x]);
	
	return 0;
}
