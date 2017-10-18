#include <iostream>
#include <cstdio>
#include <algorithm>

#define lowbit(x) (x) & (-(x))

using namespace std;

int n, m;

int data[300005], reset[300005], map[300005], tree[300005], ans[50005];

struct interval {
	int begin;
	int end;
	int k;
	int id;
} intervals[50005];

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

bool cmp(interval a, interval b) {
	return a.begin < b.begin;
}

bool _cmp(int a, int b) {
	return data[a] < data[b];
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
		reset[i] = i;
	}
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &intervals[i].begin, &intervals[i].end, &intervals[i].k);
		intervals[i].id = i;
	}
	
	sort(intervals + 1, intervals + 1 + m, cmp);
	sort(reset + 1, reset + 1 + n, _cmp);
	
	for (int i = 1; i <= n; i++) {
		map[i] = data[reset[i]];
		data[reset[i]] = i;
	}
	
	intervals[0].begin = 1;
	intervals[0].end = 0;
	
	for (int i = 1; i <= m; i++) {
		for (int j = intervals[i - 1].end + 1; j <= intervals[i].end; j++)
			update(data[j], 1);
			
		for (int j = intervals[i - 1].begin; j < intervals[i].begin; j++)
			update(data[j], -1);
			
		int l = 1, r = n, m;
		
		while (l < r) {
			m = (l + r) >> 1;
			
			if (query(m) >= intervals[i].k)
				r = m;
			else
				l = m + 1;
		}
		
		ans[intervals[i].id] = map[l];
	}
	
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}
