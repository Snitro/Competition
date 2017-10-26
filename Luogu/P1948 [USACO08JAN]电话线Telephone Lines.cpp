#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, p, k;

int tot[10005];
int t;

int maxl;

bool flg[10005];

int w[10005];

bool tot_flg[1000005];

int head[10005];

struct Edge {
	int to;
	int value;
	int next;
} edges[20005];

int edge_len = 0;

void clean() {
	memset(flg, 0, sizeof(flg));
	memset(w, 0x7f7f, sizeof(w));
}

void add(int from, int to, int value) {
	edges[++edge_len].to = to;
	edges[edge_len].value = value;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void tot_maker() {
	for (int i = 1; i <= maxl; i++)
		if (tot_flg[i])
			tot[++t] = i;
}

bool spfa(int v) {
	clean();
	
	queue <int> Q;
	
	Q.push(1);
	flg[1] = true;
	w[1] = 0;
	
	while (Q.size()) {
		int from = Q.front();
		Q.pop();
		flg[from] = false;
		
		for (int i = head[from]; i != 0; i = edges[i].next) {
			Edge &edge = edges[i];
			
			if (w[from] + (edge.value <= v ? 0 : 1) < w[edge.to]) {
				w[edge.to] = w[from] + (edge.value <= v ? 0 : 1);
				
				if (!flg[edge.to]) {
					flg[edge.to] = true;
					Q.push(edge.to);
				}
			}
		}
	}
	
	if (w[n] <= k)
		return true;
		
	return false;
}

int check() {
	int l = 1, r = t, m;

	while (l != r) {
		m = (l + r) / 2;

		if (spfa(tot[m]))
			if (spfa(tot[m - 1]))
				r = m - 1;
			else
				return tot[m];
		else
			l = m + 1;
	}
	
	if (r == t)
		return -1;
	
	return tot[l];
}
              
int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d%d%d", &n, &p, &k);

	int a, b, c;

	for (int i = 1; i <= p; i++) {
		scanf("%d%d%d", &a, &b, &c);
		
		add(a, b ,c);
		add(b, a, c);
		
		if (c > maxl)
			maxl = c;
		
		tot_flg[c] = true;
	}

	tot_maker();
	
	cout << check();

	return 0;
}
