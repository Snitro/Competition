#include <iostream>
#include <cstdio>

using namespace std;

int n, m, s;

int f[500005];

bool flg[500005];

int ans[500005];

struct Data {
    int a, b;
} datas[500005];;

struct Edge {
    int to;
    int next;
} edges[1000005];

struct qEdge {
	int to;
	int next;
	int id;
} qedges[1000005];

int head[500005];
int qhead[500005];

int edge_len = 0;

void qadd(int from, int to, int id) {
	edge_len++;
	qedges[edge_len].to = to;
	qedges[edge_len].id = id;
	qedges[edge_len].next = qhead[from];
	qhead[from] = edge_len;
}

void add(int from, int to) {
    edge_len++;
    edges[edge_len].to = to;
    edges[edge_len].next = head[from];
    head[from] = edge_len;
}

int getFrom(int a) {
    if (a == f[a])
        return a;
    return f[a] = getFrom(f[a]);
}

void merge(int a, int b) { // °Ñ a ºÏ²¢µ½ b ÏÂÃæ 
    f[getFrom(a)] = getFrom(b);
}

bool check(int a, int b) {
    return getFrom(a) == getFrom(b);
}

int getint()
{
    char ch = '*';
    while (!isdigit(ch = getchar()))
    	;
    int num = ch - '0';
    while(isdigit(ch = getchar()))
		num = num * 10 + ch - '0';
    return num;
}

void dfs(int id) {
    flg[id] = true;
    
    for (int i = head[id]; i != 0; i = edges[i].next) {
        Edge &edge = edges[i];
        
        if (flg[edge.to])
            continue;
        
        dfs(edge.to);
        
        merge(edge.to, id);
    }
    
    for (int i = qhead[id]; i != 0; i = qedges[i].next) {
    	qEdge &edge = qedges[i];
    	
    	if (!ans[edge.id] && flg[edge.to])
    		ans[edge.id] = getFrom(edge.to);
	}
}

int main() {
    freopen("in.txt", "r", stdin);
    
    n = getint();
    m = getint();
    s = getint();
    
    for (int i = 1; i <= n; i++)
        f[i] = i;
    
    int a, b;
    
    for (int i = 1; i < n; i++) {
        a = getint();
        b = getint();
        
        add(a, b);
        add(b, a);
    }
    
    edge_len = 0;
    
    for (int i = 1; i <= m; i++) {
        a = getint();
        b = getint();
        
        qadd(a, b, i);
        qadd(b, a, i);
    }
    
    dfs(s);
    
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}
