#include <iostream>
#include <cstdio>
#include <algorithm>

#define lowbit(x) x & -x

using namespace std;

int datas[40005];
int id[40005];

int ans;

int tot[40005];

int n;

void add(int x, int num) {
	while (x <= n) {
		tot[x] += num;
		x += lowbit(x);
	}
}

int query(int x) {
	int ret = 0;
	
	while (x) {
		ret += tot[x];
		x -= lowbit(x);
	}
	
	return ret;
}

bool cmp(int a, int b) {
	return datas[a] < datas[b];
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &datas[i]);
		id[i] = i;
	}
	
	sort(id + 1, id + 1 + n, cmp);
	
	for (int i = 1; i <= n; i++)
		datas[id[i]] = i;
	
	for (int i = 1; i <= n; i++) {
		add(datas[i], 1);
		ans += i - query(datas[i]);
	}
	
	cout << ans;
	
	return 0;
}
