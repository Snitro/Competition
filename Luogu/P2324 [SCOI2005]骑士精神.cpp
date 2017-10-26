#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char map[6][6];
string target[6];

int ans;

int X[] = {0, 1, 2, 2, 1,-1,-2,-2,-1},
	Y[] = {0, 2, 1,-1,-2,-2,-1, 1, 2};

void dfs(int deep, int fast, int ret, int x, int y) {
	if (ret == 0) {
		ans = deep;
		return;
	}
	
	if (deep + ret - 1 > fast || ans)
		return;
	
	int tx, ty;
	
	for (int i = 1; i <= 8 && !ans; i++) {
		tx = x + X[i];
		ty = y + Y[i];
		
		if (tx >= 1 && tx <= 5 && ty >= 1 && ty <= 5) {
			int Next = ret;
			
			if (map[y][x] != target[y][x])
				Next--;
			if (map[ty][tx] != target[ty][tx])
				Next--;
			
			map[y][x] = map[ty][tx];
			map[ty][tx] = '*';
			
			if (map[y][x] != target[y][x])
				Next++;
			if (map[ty][tx] != target[ty][tx])
				Next++;
						
			dfs(deep + 1, fast, Next, tx, ty);
			
			map[ty][tx] = map[y][x];
			map[y][x] = '*';
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
    target[1] = "011111";
    target[2] = "001111";
    target[3] = "000*11";
    target[4] = "000001";
    target[5] = "000000";
	
	int p;
	char temp[10];
	
	scanf("%d", &p);
	
	while (p--) {
		ans = 0;
		int x, y, ret = 0;
		
		for (int i = 1; i <= 5; i++) {
			scanf("%s", temp);
			for (int j = 1; j <= 5; j++) {
				map[i][j] = temp[j - 1];
				
				if (map[i][j] == '*') {
					x = j;
					y = i;
				}
				
				if (map[i][j] != target[i][j])
					ret++;
			}
		}
		
		for (int i = 1; i <= 15 && !ans; i++)
			dfs(0, i, ret, x, y);
		
		if (ans)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	
	return 0;
}
