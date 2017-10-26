#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n, p, m;

int buy[3005];

int du[3005];

int dfn[3005], low[3005], belong[3005], stack[3005], dfs_num, top, col_num;

bool vis[3005];

int head[3005];

struct Edge{
	int to;
	int next;
} edges[8005];

struct Map {
	int cop[3005];
	int head[3005];
	Edge edges[8005];
	int m;
	
	Map() {
		memset(cop, 0x7f, sizeof(cop));
		m = 0;
	}
	
	void add(int from, int to) {
		edges[++m].to = to;
		edges[m].next = head[from];
		head[from] = m;
	}
	
} map;

void add(int from, int to, int id) {
	edges[id].to = to;
	edges[id].next = head[from];
	head[from] = id;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++dfs_num;
    vis[x] = true;
    stack[++top] = x;
    
    int to;
    
    for (int i = head[x]; i; i = edges[i].next) {
        to = edges[i].to;
        
        if (!dfn[to]) {
            tarjan(to);
            
            if (low[to] < low[x])
                low[x] = low[to];
        } else if (vis[to] && dfn[to] < low[x]) 
            low[x] = dfn[to];
    }
    
    if (dfn[x] == low[x]) {
        vis[x] = false;
        belong[x] = ++col_num;
        
        while (stack[top] != x) {
            belong[stack[top]] = col_num;
            vis[stack[top--]] = false;
        }
        
        top--;
    }
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &p);
	
	int a, b;
	
	memset(buy, 0x7f, sizeof(buy));
	
	for (int i = 1; i <= p; i++) {
		scanf("%d", &a);
		scanf("%d", &buy[a]);
	}
	
	scanf("%d", &m);
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		add(a, b, i);
	}
	
	for (int i =1 ; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
			
	int to;
	
	for (int i = 1; i <= n; i++) {
		if (buy[i] < map.cop[belong[i]])
			map.cop[belong[i]] = buy[i];
		
		for (int j = head[i]; j; j = edges[j].next) {
			to = edges[j].to;
			
			if (belong[i] != belong[to]) {
				map.add(belong[i], belong[to]);
				du[belong[to]]++;
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= col_num; i++)
		if (!du[i])
			ans += map.cop[i];
	
	if (ans >= buy[0]) {
		for (int i = 1; i <= n; i++) {
			if (du[belong[i]] == 0 && map.cop[belong[i]] >= buy[0]) {
				cout << "NO" << endl << i;
				return 0;
			}
		}
		
		return 0;
	}
	
	cout << "YES" << endl << ans;
	
	return 0;
}
