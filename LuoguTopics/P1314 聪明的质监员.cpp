#include <iostream>
#include <cstring>
#include <cstdio>

#define abs(x) ((x) >= 0 ? (x) : (-(x)))

using namespace std;

int n, m, MIN = 999999999, MAX;

long long s, ans = 99999999999999, tot[200005], sum[200005];;

struct Thing {
	int w;
	int v;
} things[200005];

struct Interval {
	int l;
	int r;
} intervals[200005]; 

bool check(int w) {
	long long res = 0;
	
	memset(tot, 0, sizeof(tot));
	memset(sum, 0, sizeof(sum));
	
	for (int i = 1; i <= n; i++)
		if (things[i].w >= w) {
			sum[i] = sum[i - 1] + things[i].v;
			tot[i] = tot[i - 1] + 1;
		} else {
			sum[i] = sum[i - 1];
			tot[i] = tot[i - 1];
		}
		
	for (int i = 1; i <= m; i++)
		res += (tot[intervals[i].r] - tot[intervals[i].l - 1]) * (sum[intervals[i].r] - sum[intervals[i].l - 1]);
	
	ans = min(ans, abs(res - s));
	
	return res - s > 0;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%lld", &n, &m, &s);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &things[i].w, &things[i].v);
		if (things[i].w > MAX)
			MAX = things[i].w;
		if (things[i].w < MIN)
			MIN = things[i].w;
	}
	
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &intervals[i].l, &intervals[i].r);
	
	int l = MIN - 1, r = MAX + 1, m;
	
	while (l < r) {
		m = (l + r) >> 1;
		
		if (check(m))
			l = m + 1;
		else
			r = m;
	}
	
	cout << ans;
	
	return 0;
}
