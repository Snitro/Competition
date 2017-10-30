#include <iostream>
#include <cstdio>
#include <algorithm>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

int n;

int MIN = 999999999, MAX = -999999999;

struct Line {
	int l;
	int r;
	int y;
	int f;
} lines[10005];

struct Node {
	bool l;
	bool r;
	int num;//覆盖当前区间的线段个数 
	int cover;//区间被划分的面积 
	int tot;//数量 
} nodes[20000 << 2];

struct Rec {
	int x1;
	int y1;
	int x2;
	int y2;
} recs[5005];

void PushUP(int rt, int l, int r) {
	if (nodes[rt].num) {
		nodes[rt].l = nodes[rt].r = true;
		nodes[rt].cover = r - l + 1;
		nodes[rt].tot = 1;
	} else if (l == r) {
		nodes[rt].cover = nodes[rt].tot = 0;
		nodes[rt].l = nodes[rt].r = false;
	} else {
		nodes[rt].cover = nodes[rt << 1].cover + nodes[rt << 1 | 1].cover;
		nodes[rt].l = nodes[rt << 1].l;
		nodes[rt].r = nodes[rt << 1 | 1].r;
		nodes[rt].tot = nodes[rt << 1].tot + nodes[rt << 1 | 1].tot - (nodes[rt << 1].r && nodes[rt << 1 | 1].l);
	}
}

void update(int L, int R, int num, int l, int r, int rt) {
	if (L <= l && r <= R){
		nodes[rt].num += num;
		
		PushUP(rt, l, r);
		
		return;
	}
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, num, lson);
	if (m < R)
		update(L, R, num, rson);
		
	PushUP(rt, l, r);
}

bool cmp(Line a, Line b) {
	if (a.y == b.y)
		return a.f > b.f;
	return a.y < b.y;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &recs[i].x1, &recs[i].y1, &recs[i].x2, &recs[i].y2);
		
		MAX = max(MAX, max(recs[i].x1, recs[i].x2));
		MIN = min(MIN, min(recs[i].x1, recs[i].x2));
		
		lines[i * 2 - 1].l = lines[i * 2].l = recs[i].x1;
		lines[i * 2 - 1].r = lines[i * 2].r = recs[i].x2;
		
		lines[i * 2].y = recs[i].y1;
		lines[i * 2].f = 1;
		
		lines[i * 2 - 1].y = recs[i].y2;
		lines[i * 2 - 1].f = -1;
		
	}
	
	n <<= 1;
	
	sort(lines + 1, lines + 1 + n, cmp);
	
	long long last = 0, ans = 0;
	
	for (int i = 1; i <= n; i++) {
		if (lines[i].l <= lines[i].r)
			update(lines[i].l, lines[i].r - 1, lines[i].f, MIN, MAX - 1, 1);
			
		ans += abs(nodes[1].cover - last);
		ans += (lines[i + 1].y - lines[i].y) * 2 * nodes[1].tot;
		last = nodes[1].cover;
	}
	
	cout << ans;
	
	return 0;
}
