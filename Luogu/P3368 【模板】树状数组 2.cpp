#include <iostream>
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

long long tree[500005];

int n, m;

void add(int x, long long num) {
	while (x <= n) {
		tree[x] += num;
		x += lowbit(x);
	}
}

long long query(int x) {
	long long ans = 0;
	
	while (x) {
		ans += tree[x];
		x -= lowbit(x);
	}
	
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	long long last = 0, now;

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &now);
		add(i, now - last);
		last = now;
	}
	
	int flg;
	
	while (m--) {
		scanf("%d", &flg);
		
		if (flg == 1) {
			int x, y;
			long long k;
			
			scanf("%d%d%lld", &x, &y, &k);
			
			add(x, k);
			add(y + 1, -k);
		} else if (flg == 2) {
			int x;
			scanf("%d", &x);
			
			printf("%lld\n", query(x));
		}
	}
	
	return 0;
}
