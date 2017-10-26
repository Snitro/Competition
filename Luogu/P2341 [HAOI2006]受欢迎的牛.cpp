#include <iostream>
#include <cstdio>

using namespace std;

int n, m, sta_m;

int head[10005];

int tot[10005];

int dfn[10005];

int low[10005];

int temp[10005];

int stack[10005];

struct Edge {
	int to;
	int next;
} edges[50005];

void add(int from, int to, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	head[from] = id;
}

void tardfs(int k, int lay, int & scc_num) {
	temp[k] = 1;
	low[k] = lay;
	dfn[k] = lay;
	stack[++sta_m] = k;

	int to;
	
	for (int i = head[k]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (temp[to] == 0)
			tardfs(to, ++lay, scc_num);
			
		if (temp[to] == 1 && low[to] < low[k])
			low[k] = low[to];
	}
	
	if (dfn[k] == low[k]) {
		++scc_num;
		
		do {
			low[stack[sta_m]] = scc_num;
			temp[stack[sta_m]] = 2;
		} while (stack[sta_m--] != k);
	}
}

int tarjan() {
	int scc_num = 0, lay = 1;
	sta_m = 0;
	
	for (int i = 1; i <= n; i++)
		if (temp[i] == 0)
			tardfs(i, lay, scc_num);
			
	return scc_num;
}

int main() {
//	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int a, b;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		
		add(a, b, i);
	}
	
	int count = tarjan();
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = edges[j].next) {
			int to = low[edges[j].to];
			
			if (low[i] != to)
				tot[low[i]]++;
		}
	}
	
	int group;
	
	for (int i = 1; i <= count; i++)
		if (!tot[i]) {
			ans++;
			group = i;
		}
	
	if (ans != 1) {
		cout << 0 << endl;
		return 0;
	}
	
	ans = 0;
	
	for (int i = 1; i <= n; i++)
		if (low[i] == group)
			ans++;
	
	cout << ans;
	
	return 0;
}
