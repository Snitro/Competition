#include<iostream>
#include<cstdio>

using namespace std;

int head[200005];
int n;
int edge_len = 0;
int F[200005];
bool visit[200005];

struct Edge {
	int next;
	int to;
}edge[200005];

void add(int from,int to) {
	edge_len++;
	edge[edge_len].to = to;
	edge[edge_len].next = head[from];
	head[from] = edge_len;
}

bool dfs(int id) {
	int tot = 0;
	int y = 0;
	visit[id] = true;
	for (int i = head[id]; i != 0; i = edge[i].next) {
		int to = edge[i].to;
		if (!visit[to]) {
			bool re = dfs(to);
			tot++;
			if (re)
				y++;
			else 
				F[id] += F[to];
		}
	}
	y++;
	F[id] += y / 2;
	if(tot == 0 && F[id] == 0) {
		F[id] = 1;
		return true;
	}
	return false;
}

int main() {
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int a,b;
	visit[1] = true;
	for (int i = 1; i < n; i++) {
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1);
	cout << F[1] << endl;
}
