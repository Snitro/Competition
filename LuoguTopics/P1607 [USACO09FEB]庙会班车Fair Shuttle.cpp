#include <iostream> 
#include <cstdio>
#include <algorithm>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

int k, n, c, temp;

long long ans = 0;

struct Node {
	int s;
	int e;
	int k;
} nodes[50005];

int MAX[20000 << 2], color[20000 << 2];

void PushDown(int rt) {
	if (color[rt]) {
		MAX[rt << 1] += color[rt];
		MAX[rt << 1 | 1] += color[rt];
		
		color[rt << 1] += color[rt];
		color[rt << 1 | 1] += color[rt];
		
		color[rt] = 0;
	}
}

void PushUP(int rt) {
	MAX[rt] = max(MAX[rt << 1], MAX[rt << 1 | 1]);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R)
		return MAX[rt];
	
	PushDown(rt);
	
	int m = (l + r) >> 1;
	int ret = -1;
	
	if (L <= m)
		ret = query(L, R, lson);
	if (m < R)
		ret = max(ret, query(L, R, rson));
	
	return ret;
}

void update(int L, int R, int num, int l, int r, int rt) {
	if (L <= l && r <= R) {
		color[rt] += num;
		MAX[rt] += num;
		return;
	}
	
	PushDown(rt);
	
	int m = (l + r) >> 1;
	
	if (L <= m)
		update(L, R, num, lson);
	if (m < R)
		update(L, R, num, rson);
		
	PushUP(rt);
}

bool cmp(Node a, Node b) {
	if (a.e == b.e)
		return a.s < b.s;
		
	return a.e < b.e;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &k, &n, &c);
	
	for (int i = 1; i <= k; i++)
		scanf("%d%d%d", &nodes[i].s, &nodes[i].e, &nodes[i].k);
	
	sort(nodes + 1, nodes + 1 + k, cmp);
	
	for (int i = 1; i <= k; i++)  {
		temp = query(nodes[i].s, nodes[i].e, root);
		
		if (temp <= c) {
			update(nodes[i].s, nodes[i].e - 1, min(nodes[i].k, c - temp), root);
			
			ans += min(nodes[i].k, c - temp);
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}
