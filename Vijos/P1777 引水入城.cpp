#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

bool vis[505][505];

int map[505][505];

struct Node {
	int x;
	int y;
} pos[250005];

queue <Node> que;

struct Q {
	int begin;
	int end;
} ran[505], use[505][505];

bool cmp(Node a, Node b) {
	return map[a.y][a.x] < map[b.y][b.x];
}

bool cmp2(Q a, Q b) {
	return a.begin < b.begin;
}

void bfs() {
	Node temp, ne;
	
	temp.y = 1;
	
	for (int i = 1; i <= m; i++) {
		temp.x = i;
		vis[temp.x][temp.y] = true;
		que.push(temp);
	}
	
	while (que.size()) {
		temp = que.front();
		que.pop();
		
		if (map[temp.y][temp.x] > map[temp.y][temp.x + 1] && !vis[temp.x + 1][temp.y]) {
			ne.x = temp.x + 1;
			ne.y = temp.y;
			vis[temp.x + 1][temp.y] = true;
			que.push(ne);
		}
		if (map[temp.y][temp.x] > map[temp.y][temp.x - 1] && !vis[temp.x - 1][temp.y]) {
			ne.x = temp.x - 1;
			ne.y = temp.y;
			vis[temp.x - 1][temp.y] = true;
			que.push(ne);
		}
		if (map[temp.y][temp.x] > map[temp.y + 1][temp.x] && !vis[temp.x][temp.y + 1]) {
			ne.x = temp.x;
			ne.y = temp.y + 1;
			vis[temp.x][temp.y + 1] = true;
			que.push(ne);
		}
		if (map[temp.y][temp.x] > map[temp.y - 1][temp.x] && !vis[temp.x][temp.y - 1]) {
			ne.x = temp.x;
			ne.y = temp.y - 1;
			vis[temp.x][temp.y - 1] = true;
			que.push(ne);
		}
	}
	
	int tot = 0;
	
	for (int i = 1; i <= m; i++)
		if (!vis[i][n])
			tot++;
	
	if (tot) {
		cout << 0 << endl << tot;
		exit(0);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			pos[(i - 1) * m + j].x = j;
			pos[(i - 1) * m + j].y = i;
		}
		
	bfs();
		
	sort(pos + 1, pos + 1 + n * m, cmp);
	
	int x, y;

	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++) {
			use[i][j].begin = 999999999;
			use[i][j].end = -999999999;
		}
	
	for (int i = 1; i <= n * m; i++) {
		x = pos[i].x;
		y = pos[i].y;
		
		if (map[y][x + 1] < map[y][x]){
			use[y][x].begin = min(use[y][x].begin, use[y][x + 1].begin);
			use[y][x].end = max(use[y][x].end, use[y][x + 1].end);
		}
		if (map[y][x - 1] < map[y][x]) {
			use[y][x].begin = min(use[y][x].begin, use[y][x - 1].begin);
			use[y][x].end = max(use[y][x].end, use[y][x - 1].end);
		}
		if (map[y + 1][x] < map[y][x]) {
			use[y][x].begin = min(use[y][x].begin, use[y + 1][x].begin);
			use[y][x].end = max(use[y][x].end, use[y + 1][x].end);
		}
		if (map[y - 1][x] < map[y][x]) {
			use[y][x].begin = min(use[y][x].begin, use[y - 1][x].begin);
			use[y][x].end = max(use[y][x].end, use[y - 1][x].end);
		}
		
		if (y == n) {
			if (use[y][x].begin > x)
				use[y][x].begin = x;
			if (use[y][x].end < x )
				use[y][x].end = x;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		ran[i].begin = use[1][i].begin;
		ran[i].end = use[1][i].end;
	}
	
	sort(ran + 1, ran + 1 + m, cmp2);
	
	int tot = 0, po = 1, fast = 0;
	
	for (int i = 1; i <= m; i++) {
		fast = 0;
		
		while (ran[po].begin <= i) {
			fast = max(fast, ran[po].end);
			po++;
		}
		
		tot++;
		i = fast;
	}
	
	cout << 1 << endl << tot << endl;
	
	return 0;
}
