#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, m, s, t;

int head[5005], edge_len;

struct Edge {
	int to;
	double value;
	int next;
} edges[2000005];

bool visit[5005];

double value[5005];

queue <int> que;

void add(int from, int to, double value) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	edges[edge_len].value = value;
	head[from] = edge_len;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d%d", &n, &m, &s, &t);
	
	int u, v;
	double c;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lf", &u, &v, &c);
		add(u, v, c);
	}
	
	value[s] = 1;
	que.push(s);
	visit[s] = true;
	
	while (que.size()) {
		int x = que.front();
		que.pop();
		int to;
		
		for (int i = head[x]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (value[x] * edges[i].value > value[to]) {
				value[to] = value[x] * edges[i].value;
				
				if (!visit[to]) {
					que.push(to);
					visit[to] = true;
				}
			}
		}
	}
	
	if (value[t])
		printf("%.4f", value[t]);
	else
		cout << "orz";
	
	return 0;
}
