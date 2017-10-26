#include <iostream>
#include <cstdio>

using namespace std;

int n, m, s;

int head[500005], edge_len;

int p[500005][25], fa[500005], deep[500005];

struct Edge {
	int to;
	int next;
} edges[1000005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

int read(){
    int re=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9'){ 
        re=re*10+ch-'0'; 
        ch=getchar();
    }
    return re;
}

void dfs(int x) {
    p[x][0] = fa[x];

    for (int i = 1; p[x][i-1]; i++)
        p[x][i] = p[p[x][i - 1]][i - 1];

    int to;

    for (int i = head[x]; i; i = edges[i].next) {
        to = edges[i].to;

        if (to != fa[x]) {
            fa[to] = x;
            deep[to] = deep[x] + 1;
            dfs(to);
        }
    }
}

int lca(int a,int b){
    if(deep[a] > deep[b])
        swap(a, b);

    int f = deep[b] - deep[a];
    for (int i = 0; (1 << i) <= f; i++)
        if((1 << i) & f)
            b = p[b][i];

    if (a != b) {
        for (int i = 19; i >= 0; i--)
            if (p[a][i] != p[b][i]) {
                a = p[a][i];
                b = p[b][i];
            }

        a = p[a][0];
    }
    return a;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	n = read();
	m = read();
	s = read();
	
	int from, to;
	
	for (int i = 1; i < n; i++) {
		from = read();
		to = read();
		
		add(from, to);
		add(to, from);
	}
	
	dfs(s);
	
	for (int i = 1; i <= m; i++) {
		from = read();
		to = read();
		
		printf("%d\n", lca(from, to));
	}
	
	return 0;
}
