#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

struct Edge {
	int to;
	int next;
} edges[50005];

int head[10005];

int tot[10005];

int low[10005], temp[10005], dfn[10005], stack[10005];
int stack_m;

void add(int from, int to, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	head[from] = id;
}

void tarbfs(int k, int lay, int & scc_num) {
	temp[k] = 1;
	low[k] = lay;
	dfn[k] = lay;
	stack[++stack_m] = k;
	
	for (int i = head[k]; i; i = edges[i].next) {
		if (!temp[edges[i].to])
			tarbfs(edges[i].to, ++lay, scc_num);
			
		if (temp[edges[i].to] == 1 && low[edges[i].to] < low[k])
			low[k] = low[edges[i].to];
	}
	
	if (dfn[k] == low[k]) {
		scc_num++;
		
		do {
			low[stack[stack_m]] = scc_num;
			temp[stack[stack_m]] = 2;
		} while (stack[stack_m--] != k);
	}
}

int tarjan() {
	int scc_num = 0, lay = 1;
	stack_m = 0;
	
	for (int i = 1; i <= n; i++)
		if (temp[i] == 0)
			tarbfs(i, lay, scc_num);
	
	return scc_num;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int a, b;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		
		add(a, b, i);
	}
	
	int num = tarjan();
	
	for (int i = 1; i <= n; i++)
		if (temp[i] == 2) {
			tot[low[i]]++;
			
			if (tot[low[i]] == 1)
				num--;
			if (tot[low[i]] == 2)
				num++;
		}
		
	cout << num << endl;
	
	return 0;
}
