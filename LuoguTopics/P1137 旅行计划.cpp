#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue <int> que;

struct Edge {
	int to;
	int next;
} edges[200005];

int n, m, top_len;

int top[100005];

int head[100005];

int f[100005];

int du[100005];

void add(int from, int to, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	head[from] = id;
}
int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int a, b;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		
		add(a, b, i);
		du[b]++;
	}
	
	for (int i = 1; i <= n; i++)
		if (!du[i])
			que.push(i);
	
	while (que.size()) {
		top[++top_len] = que.front();
		que.pop();
		
		for (int i = head[top[top_len]]; i; i = edges[i].next) {
			du[edges[i].to]--;
			
			if (!du[edges[i].to])
				que.push(edges[i].to);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!f[top[i]])
			f[top[i]] = 1;
		
		for (int j = head[top[i]]; j; j = edges[j].next)
			if (f[top[i]] + 1 > f[edges[j].to])
				f[edges[j].to] = f[top[i]] + 1;
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d\n", f[i]);
	
	return 0;
}
