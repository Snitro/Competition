#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, m;

struct Node {
	int du;
	int id;
	
	Node (int du, int id) {
		this -> du = du;
		this -> id = id;
	}
	
	bool operator < (Node a) const {
		if (du != a.du)
			return du > a.du;
		
		return id < a.id;
	}
};

priority_queue <Node> nodes;

struct Edge {
	int to;
	int next;
} edges[200005];

int head[100005];

bool flg[100005];

int du[100005];

int ans[100005];

int ans_len;

int map[100005];

void add(int from, int to, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	head[from] = id;
}

int main() {
	//freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int x, y;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		
		add(y, x, i);
		
		du[x]++;
	}
	
	for (int i = n; i >= 1; i--)
		if (!du[i])
			nodes.push(Node(0, i));
	
	
	for (int i = 1; i <= n; i++) {
		Node node = nodes.top();
		nodes.pop();
		
		while (flg[node.id]) {
			node = nodes.top();
			nodes.pop();
		}
		
		
		flg[node.id] = true;
		ans[++ans_len] = node.id;
		
		for (int a = head[node.id]; a; a = edges[a].next) {
			du[edges[a].to]--;
			nodes.push(Node(du[edges[a].to], edges[a].to));
		}
	}
	
	for (int i = 1; i <= ans_len; i++)
		map[ans[i]] = n + 1 - i;
		
	for (int i = 1; i <= n; i++)
		printf("%d ", map[i]);
	
	return 0;
}
