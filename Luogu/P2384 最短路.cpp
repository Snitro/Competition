#include <iostream>
#include <cstdio>
#include <queue>
#define mod 9987;
using namespace std;

int n, m;

queue <int> Q;

long long ans[1005];

bool flg[1005];

int head[1005];

struct Edge {
	int to;
	int value;
	int next;
} edges[1000000];

void add(int from, int to, int value, int id) {
	edges[id].to = to;
	edges[id].value = value;
	edges[id].next = head[from];
	head[from] = id;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int x, y, z;
	
	for (int i = 1; i <= n; i++)
		ans[i] = 999999999;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z, i);
	}
	
	Q.push(1);
	flg[1] = true;
	ans[1] = 1;
	
	while (Q.size()) {
		int from = Q.front();
		Q.pop();
		
		for (int i = head[from]; i != 0; i = edges[i].next) {
			Edge &edge = edges[i];
			
			if (ans[from] * edge.value < ans[edge.to]) {
				ans[edge.to] = ans[from] * edge.value;
				
				if (!flg[edge.to]) {
					flg[edge.to] = true;
					Q.push(edge.to);
				}
			}
		}
	}
	
	cout << ans[n] % mod;
	
	return 0;
}

