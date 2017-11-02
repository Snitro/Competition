#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int deep[100005], head[100005], fa[100005], edge_len;

int ans, n, k, t;

bool set[100005], vis[100005];

struct Edge {
	int to;
	int next;
} edges[200005];

struct Node {
	int x;
	
	Node(int x) {
		this -> x = x;
	}
	
	bool operator < (Node to) const {
		return deep[x] < deep[to.x];
	}
};

priority_queue <Node> que;

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x) {
	int to;
	bool flag = false;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (deep[to] == 0) {
			flag = true;
			fa[to] = x;
			deep[to] = deep[x] + 1;
			dfs(to);
		}
	}
	
	if (!flag)
		que.push(Node(x));
}

void setter(int x, int n) {
	vis[x] = true;
	set[x] = true;
		
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!vis[to]) {
			if (n == 0)
				que.push(Node(to));
			else
				setter(to, n - 1);
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &k, &t);
	
	int u, v;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		
		add(v, u);
		add(u, v);
	}
	
	deep[1] = 1;
	fa[1] = 1;
	dfs(1);
	
	while (que.size()) {
		Node t = que.top();
		que.pop();
		
		if (!set[t.x]) {
			memset(vis, 0, sizeof(vis));
			int x = t.x;
			
			for (int i = 1; i <= k; i++)
				x = fa[x];
			
			ans++;
			setter(x, k);
		}
	}
	
	cout << ans;
	
	return 0;
}
