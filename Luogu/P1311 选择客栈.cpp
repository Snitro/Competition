#include <iostream>
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

int n, k, p;

int col[200005];

int f[200005];

int tree[55][200005];

long long ans;

void add(int col, int x, int num) {
	while (x <= n) {
		tree[col][x] += num;
		x += lowbit(x);
	}
}

int query(int col, int x) {
	if (x <= 0)
		return 0;
	
	int ans = 0;
	
	while (x) {
		ans += tree[col][x];
		x -= lowbit(x);
	}
	
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &k, &p);
	
	int tmp;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &col[i], &tmp);
		
		col[i]++;
		
		if (tmp <= p)
			f[i] = i;
			
		add(col[i], i, 1);
	}
	
	for (int i = n; i >= 1; i--)
		if (!f[i])
			f[i] = f[i + 1];
	
	for (int i = 1; i <= n; i++)
		if (f[i])
			ans += query(col[i], n) - query(col[i], f[i] - 1);
	cout << ans;
	
	return 0;
}
