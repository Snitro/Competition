#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int w[10005];

long long ans;

struct board {
	int l;
	int r;
	int h;
} boards[105];

bool cmp(board a, board b) {
	return a.h < b.h;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &boards[i].h, &boards[i].l, &boards[i].r);
		
	sort(boards + 1, boards + 1 + n, cmp);
	
	for (int i = 1; i <= n; i++) {
		board  &t = boards[i];
		
		ans += (t.h - w[t.l + 1]) + (t.h - w[t.r]);
		
		for (int j = t.l + 1; j <= t.r; j++)
			w[j] = t.h;
	}
	
	cout << ans;
	
	return 0;
}
