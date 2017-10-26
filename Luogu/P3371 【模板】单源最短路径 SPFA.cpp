#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue <int> Q;

bool flg[10005];

int ans[10005];

int n, m, s;

int head[10005];

struct Edge {
	int to;
	int next;
	int value;
} edges[500005];

void add(int from, int to, int value, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	edges[id].value = value;
	head[from] = id;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &s);
	
	for (int i = 1; i <= n; i++)
		ans[i] = 999999999;
	
	int f, t, v;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &f, &t, &v);
		add(f, t, v, i);
	}
	
	Q.push(s);
	flg[s] = true;
	ans[s] = 0;
	
	while (Q.size()) {
		int front = Q.front();
		Q.pop();
		flg[front] = false;
		
		for (int i = head[front]; i != 0; i = edges[i].next) {
			Edge &edge = edges[i];
			
			if (ans[front] + edge.value < ans[edge.to]) {
				ans[edge.to] = ans[front] + edge.value;
				
				if (!flg[edge.to]) {
					Q.push(edge.to);
					flg[edge.to] = true;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i] == 999999999 ? 2147483647 : ans[i]);
	
	return 0;
}
