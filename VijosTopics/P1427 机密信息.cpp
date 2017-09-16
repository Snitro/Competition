#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
	int id;
	int len;
	int t;
	
	Node() {
	}
	
	Node(int id, int len, int t) {
		this -> id = id;
		this -> len = len;
		this -> t = t;
	}
};

queue <Node> que;

int n, s, t;

bool vis[10005];

int list[10005];

int strLen[10005], edge_len, head[10005];

struct Edge {
	int to;
	int next;
} edges[20005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &s, &t);
	
	int from, to;
	string len;
	
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &from, &to);
		
		add(from, to);
		add(to, from);
		
		cin >> len;
		strLen[from] = len.size();
		list[to]++;
	}
	
	que.push(Node(s, strLen[s], 0));
	vis[s] = true;
	
	Node front;
	
	while (que.size()) {
		front = que.front();
		que.pop();
		
		if (front.id == t) {
			cout << front.len << endl << (front.t - list[t]);
			return 0;
		}
		
		for (int i = head[front.id]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (!vis[to]) {
				vis[to] = true;
				que.push(Node(to, strLen[to] + front.len, list[to] + front.t));
			}
		}
	}
	
	return 0;
}
