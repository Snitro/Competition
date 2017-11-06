#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int n, datas[1005], f[1005], col[1005];

int head[1005], edge_len;

struct Edge {
	int to;
	int next;
} edges[2000005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void dfs(int x) {
	int to;
	
	for (int i = head[x]; i; i = edges[i].next) {
		to = edges[i].to;
		
		if (!col[to]) {
			col[to] = col[x] == 1 ? 2 : 1;
			dfs(to);
		} else {
			if (col[to] == col[x]) {
				puts("0");
				exit(0);
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &datas[i]);
		
	f[n + 1] = 999999999;
	
	for (int i = n; i >= 1; i--)
		f[i] = min(f[i + 1], datas[i]);
	
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if ((datas[j] > datas[i] && f[j + 1] < datas[i])) {
				add(i, j);
				add(j, i);
			}
	
	for (int i = 1; i <= n; i++)
		if (!col[i]) {
			col[i] = 1;
			dfs(i);
		}
	
	int now = 1;
	
	stack <int> s1, s2;
	
	for (int i = 1; i <= n; i++) {
		if (col[i] == 1) {
			s1.push(datas[i]);
			printf("a ");
		} else {
			s2.push(datas[i]);
			printf("c ");
		}
		
		while ((s1.size() && s1.top() == now) || (s2.size() && s2.top() == now)) {
			while (s1.size() && s1.top() == now) {
				s1.pop();
				now++;
				
				printf("b ");
			}
			
			while (s2.size() && s2.top() == now) {
				s2.pop();
				now++;
				
				printf("d ");
			}
		}
	}
	
	return 0;
}
