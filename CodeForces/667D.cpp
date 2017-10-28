#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int ans, list[4];

int head[3005], edge_len;

int From[3005][3], To[3005][3], map[3005][3005];

struct Edge {
	int to;
	int next;
} edges[5005];

void add(int from, int to) {
	edges[++edge_len].to = to;
	edges[edge_len].next = head[from];
	head[from] = edge_len;
}

void bfs(int x) {
	queue <int> que;
	
	que.push(x);
	map[x][x] = 0;
	
	int from, to;
	
	while (que.size()) {
		from = que.front();
		que.pop();
		
		for (int i = head[from]; i; i = edges[i].next) {
			to = edges[i].to;
			
			if (map[x][to] == -1) {
				map[x][to] = map[x][from] + 1;
				que.push(to);
				
				if (map[x][to] > map[x][From[x][0]]) {
					From[x][2] = From[x][1];
					From[x][1] = From[x][0];
					From[x][0] = to;
				} else if (map[x][to] > map[x][From[x][1]]) {
					From[x][2] = From[x][1];
					From[x][1] = to;
				} else if (map[x][to] > map[x][From[x][1]])
					From[x][2] = to;
					
				if (map[x][to] > map[To[to][0]][to]) {
					To[to][2] = To[to][1];
					To[to][1] = To[to][0];
					To[to][0] = x;
				} else if (map[x][to] > map[To[to][1]][to]) {
					To[to][2] = To[to][1];
					To[to][1] = x;
				} else if (map[x][to] > map[To[to][2]][to])
					To[to][2] = x;
			}
		}
	}
}

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d", &n, &m);
	
	memset(map, -1, sizeof(map));
	
	int u, v;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		
		add(u, v);
	}
	
	for (int i = 1; i <= n; i++)
		bfs(i);
	
	int a, d;

	for (int b = 1; b <= n; b++)
		for (int c = 1; c <= n; c++)
			if (b != c && map[b][c] != -1)
				for (int i = 0; i <= 2; i++)
					for (int j = 0; j <= 2; j++) {
						a = To[b][i];
						d = From[c][j];
						
						if (a != b && a != c && a != d && b != c && b != d && c != d) {
							if (map[a][b] + map[b][c] + map[c][d] > ans) {
								ans = map[a][b] + map[b][c] + map[c][d];
								list[0] = a;
								list[1] = b;
								list[2] = c;
								list[3] = d;
							}
						}
					}
	
	for (int i = 0; i <= 3; i++)
		printf("%d ", list[i]);
	
	return 0;
}
