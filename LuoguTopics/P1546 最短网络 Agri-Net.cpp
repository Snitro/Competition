#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int f[105];

struct Edge {
	int f;
	int t;
	int v;
}edge[10005];
int edge_len = 0;

bool cmp(Edge a, Edge b) {
	return a.v < b.v;
}

void add(int f, int t, int len) {
	edge_len++;
	edge[edge_len].f = f;
	edge[edge_len].t = t;
	edge[edge_len].v = len;
}
int getFrom(int p) {
	if (p == f[p])
		return p;
	return f[p] = getFrom(f[p]);
}

void Union(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	int in;
	
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			scanf("%d", &in);
			if (in)
				add (i, j, in);
		}
	
	sort(edge + 1, edge + 1 + edge_len, cmp);
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	long long tot = 0;
	int f, t;
	
	for (int i = 1; i <= edge_len; i++) {
		f = getFrom(edge[i].f);
		t = getFrom(edge[i].t);
		if (f != t) {
			Union(f, t);
			tot += edge[i].v;			
		}
	}

	printf("%d", tot);
	
	return 0;
}
