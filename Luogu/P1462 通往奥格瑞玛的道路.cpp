#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
long long b;

long long value[10005], value_sort[10005];

int head[10005], edge_len;

int f[10005];

bool flg[10005];

struct Edge {
	int to;
	int next;
	int value;
} edges[100005];

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

bool SPFA(int MAX) {
	if (value[1] > MAX)
		return false;
	
	memset(flg, 0, sizeof(flg));
	for (int i = 1; i <= n; i++) 
		f[i] = 1e9;
	
	queue <int> que;
	que.push(1);
	f[1] = 0;
	flg[1] = true;
	int from, to;
	
	while (que.size()) {
		from = que.front();
		que.pop();
		flg[from] = false;
		
		for (int i = head[from]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (value[to] <= MAX && f[from] + edges[i].value < f[to]) {
				f[to] = f[from] + edges[i].value;
				
				if (!flg[to]) {
					flg[to] = true;
					que.push(to);
				}
			}
		}
	}
	
	return f[n] <= b;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%lld", &n, &m, &b);
	
	int from, to, v;
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &value[i]);
		value_sort[i] = value[i];
	}
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &from, &to, &v);
		
		add(from, to, v);
		add(to, from, v);
	}
	
	sort(value_sort + 1, value_sort + 1 + n);
	
	if (!SPFA(value_sort[n])) {
		cout << "AFK";
		return 0;
	}
	
	int l = 1, r = n, m;
	
	while (l < r) {
		m = (l + r) >> 1;
		
		if (SPFA(value_sort[m]))
			r = m;
		else
			l = m + 1;
	}
	
	cout << value_sort[l];
	
	return 0;
}
