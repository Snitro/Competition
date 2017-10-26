#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

bool bfs_flg[10005];
bool node_flg[10005];
bool maker_flg[10005];

int head[10005];
int head_to[10005];

struct Edge_to {
	int from;
	int next;
} edges_to[200005];

struct Edge {
	int to;
	int next;
} edges[200005];

struct Node {
	int node;
	int value;
	
	Node();
	Node(int, int);
};

Node::Node(int node, int value) {
	this -> node = node;
	this -> value = value;
}

queue <Node> Q;

void add(int from, int to, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	head[from] = id;
	edges_to[id].from = from;
	edges_to[id].next = head_to[to];
	head_to[to] = id;
}

void flg_maker(int node) {
	if (bfs_flg[node])
		return;
	
	bfs_flg[node] = true;
	
	maker_flg[node] = true;
	
	for (int i = head_to[node]; i != 0; i = edges_to[i].next)
		flg_maker(edges_to[i].from);
}

void setter(int node){
	for (int i = head[node]; i != 0; i = edges[i].next) {
		Edge &edge = edges[i];
		
		if (!maker_flg[edge.to]) {
			node_flg[edge.to] = false;
			return;
		}
	}
	
	node_flg[node] = true;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int x, y;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		add(x, y, i);
	}
	
	cin >> x >> y;
	
	flg_maker(y);
	
	for (int i = 1; i <= n; i++)
		setter(i);
	
	if (!maker_flg[x] || !node_flg[x]) {
		cout << -1;
		return 0;
	}
	
	/*
	for (int i = 1; i <= n; i++)
		cout << node_flg[i] << " ";
	cout << endl;
	*/
	
	memset(bfs_flg, 0, sizeof(bfs_flg));
	
	Q.push(Node(x, 0));
	bfs_flg[x]  = true;
	
	while (Q.size()) {
		Node node = Q.front();
		Q.pop();
		
		for (int i = head[node.node]; i != 0; i = edges[i].next) {
			Edge &edge = edges[i];
			
			if (!node_flg[edge.to])
				continue;
				
			if (edge.to == y) {
				cout << node.value + 1;
				return 0;
			}
			
			if (!bfs_flg[edge.to]) {
				bfs_flg[edge.to] = true;
				Q.push(Node(edge.to, node.value + 1));
			}
		}
	}
	
	cout << -1;
	
	return 0;
}

