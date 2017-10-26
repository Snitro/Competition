#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int dfn[200005], low[200005], stack[200005], belong[200005], dfs_num, col_num, top;

bool vis[200005];

queue <int> que;

int value[200005];

struct Edge {
	int to;
	int value;
	int next;
};

struct Map {
	Edge edges[1000005];
	int head[200005];
	int m;
	
	Map() {
		m = 0;	
	}
	
	void add(int from, int to, int value) {
		edges[++m].to = to;
		edges[m].value = value;
		edges[m].next = head[from];
		head[from] = m;
	}
	
} map1, map2;

void tarjan(int x) {
    dfn[x] = low[x] = ++dfs_num;
    vis[x] = true;
    stack[++top] = x;
    
    int to;
    
    for (int i = map1.head[x]; i; i = map1.edges[i].next) {
        to = map1.edges[i].to;
        
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
	
	scanf("%d%d", &n, &m);
	
	int a, b, c; 
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		
		map1.add(a, b, c);
	}
	
	for (int i = 1; i<= n; i++)
		if (!dfn[i])
			tarjan(i);
			
	for (int i = 1; i <= n; i++)
		for (int j = map1.head[i]; j; j = map1.edges[j].next) {
			a = map1.edges[j].to;
			
			if (belong[i] != belong[a])
				map2.add(belong[i], belong[a], map1.edges[j].value);
		}
	
	memset(vis, 0, sizeof(vis))	;
	memset(value, 0x7f, sizeof (value));
	
	que.push(belong[1]);
	vis[belong[1]] = true;
	value[belong[1]] = 0;
	
	while (que.size()) {
		a = que.front();
		que.pop();
		vis[a] = false;
		
		for (int i = map2.head[a]; i; i = map2.edges[i].next) {
			b = map2.edges[i].to;
			
			if (value[b] > value[a] + map2.edges[i].value) {
				value[b] = value[a] + map2.edges[i].value;
				
				if (!vis[b]) {
					vis[b] = true;
					que.push(b);
				}
			}
		}
	}
	
	cout << value[belong[n]];
	
	return 0;
}
