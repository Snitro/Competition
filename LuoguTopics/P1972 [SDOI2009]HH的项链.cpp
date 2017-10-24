#include <iostream>
#include <cstdio>
#include <algorithm>

#define lowbit(x) ((x) & (-(x)))

using namespace std;

int n, m, id[200005], types[50005], tree[50005], last[1000005];

struct Query {
	int begin;
	int end;
	int ans;
} datas[200005];

bool cmp(int a, int b) {
	return datas[a].end < datas[b].end;
}

void update(int x, int num) {
	while (x <= n) {
		tree[x] += num;
		x += lowbit(x);
	}
}

int query(int x) {
	int ret = 0;
	
	while (x) {
		ret += tree[x];
		x -= lowbit(x);
	}
	
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) 
		scanf("%d", &types[i]);
	
	scanf("%d", &m);
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &datas[i].begin, &datas[i].end);
		id[i] = i;
	}
		
	sort(id + 1, id + 1 + m, cmp);
	
	int pos = 0;
	
	for (int i = 1; i <= n && pos < m; i++) {
		if (last[types[i]])
			update(last[types[i]], -1);
			
		last[types[i]] = i;
		update(i, 1);
		
		while (datas[id[pos + 1]].end == i) {
			pos++;
			datas[id[pos]].ans = query(i) - query(datas[id[pos]].begin - 1);
		}
	}
	
	for (int i = 1; i <= m; i++)
		printf("%d\n", datas[i].ans);
	
	return 0;
}
