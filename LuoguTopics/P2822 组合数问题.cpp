#include <cstdio>
#include <iostream>
#include <cstring>

#define lowbit(x) x & -x

using namespace std;

int t, k;

int map[2005][2005];

int tot[2005][2005];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &t, &k);
	
	memset(map, 1, sizeof(map));
	
	for (int i = 1; i <= 2000; i++) {
		map[i][0] = map[i][i] = 1;
		for (int j = 1; j < i; j++)
			map[i][j] = (map[i - 1][j] + map[i - 1][j - 1]) % k;
	}
	
	int count;
	
	for (int i = 1; i <= 2000; i++) {
		count = 0;
		for (int j = 1; j <= 2000; j++) {
			count += (map[i][j] == 0);
			tot[i][j] = tot[i - 1][j] + count;
		}
	}
	
	int a, b;
	
	for (int i = 1; i <= t; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", tot[a][min(a, b)]);
	}
	
	return 0;
}
