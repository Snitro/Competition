#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int n, m;

bool flg[5005];

int f[5005];

struct Edge {
	int from;
	int to;
	double value;
} edges[1000005];

stack <Edge> ans;

int edge_len;

struct Node {
	int x;
	int y;
} nodes[5005];

void add(int from, int to, double value) {
	edge_len++;
	edges[edge_len].from = from;
	edges[edge_len].to = to;
	edges[edge_len].value = value;
}

bool cmp(Edge a, Edge b) {
	return a.value < b.value;
}

int getFrom(int id) {
	if (id == f[id])
		return id;
	return f[id] = getFrom(f[id]);
}

void Union(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

bool check(int a, int b) {
	return (getFrom(a) == getFrom(b));
}

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
		f[i] = i;
	
	for (int i = 1; i <= m; i++) {
		cin >> nodes[i].x >> nodes[i].y;
		
		for (int j = 1; j < i; j++)
			add(j, i, sqrt(((long long)nodes[i].x - nodes[j].x) * ((long long)nodes[i].x - nodes[j].x) +
			((long long)nodes[i].y - nodes[j].y) * ((long long)nodes[i].y - nodes[j].y)));
	}
	
	sort(edges + 1, edges + 1 + edge_len, cmp);
	
	int cnt = 0;
	
	for (int i = 1; i <= edge_len && cnt < m - n; i++) {
		Edge &edge = edges[i];
		
		if (!check(edge.from, edge.to)) {
			Union(edge.from, edge.to);
			ans.push(edge);
			cnt++;
		}
	}
	
	printf("%.2f", ans.top().value);
	
	return 0;
}
