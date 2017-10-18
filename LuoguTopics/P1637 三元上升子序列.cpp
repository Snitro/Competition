#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define lowbit(x) ((x) & (-(x)))

using namespace std;

int n;

int datas[30005], _sort[30005];

int tree[30005], _tree[30005];

void update(int * tree, int x, int num) {
	if (num == 0)
		return;
	
	while (x <= n) {
		tree[x] += num;
		x += lowbit(x);
	}
}

int query(int * tree, int x) {
	int ret = 0;
	
	while (x) {
		ret += tree[x];
		x -= lowbit(x);
	}
	
	return ret;
}

bool cmp(int a, int b) {
	return datas[a] < datas[b];
}

void init() {
	int data[30005];
	sort(_sort + 1, _sort + 1 + n, cmp);

	int i = 0;
	
	for (int j = 1; j <= n; j++)	 {
		if (j == 1 || datas[_sort[j]] != datas[_sort[j - 1]])
			i++;
		data[_sort[j]] = i;
	}
	
	memcpy(datas, data, sizeof(data));
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &datas[i]);
		_sort[i] = i;
	}
	
	init();
	
	long long ans = 0;
	
	for (int i = 1; i <= n; i++) {
		ans += query(_tree, datas[i] - 1);
		
		update(_tree, datas[i], query(tree, datas[i] - 1));
		update(tree, datas[i], 1);
	}
	
	printf("%lld", ans);
		
	return 0;
}
