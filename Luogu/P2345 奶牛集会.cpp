#include <iostream>
#include <cstdio>
#include <algorithm>

#define lowbit(x) ((x) & (-(x)))

using namespace std;

int n;

long long ans;

struct Node {
	int value;
	int pos;
} nodes[100005];

int sum[20005], tot[20005];

void update(int * tree, int x, int num) {
	while (x <= 20004) {
		tree[x] += num;
		x += lowbit(x);
	}
}

long long query(int * tree, int x) {
	long long ret = 0;

	while (x) {
		ret += tree[x];
		x -= lowbit(x);
	}

	return ret;
}

bool cmp(Node a, Node b) {
	return a.value > b.value;
}

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &nodes[i].value, &nodes[i].pos);
		update(sum, nodes[i].pos, nodes[i].pos);
		update(tot, nodes[i].pos, 1);
	}

	sort(nodes + 1, nodes + 1 + n, cmp);

	for (int i = 1; i <= n; i++) {
		ans += ((query(sum, 20004) - query(sum, nodes[i].pos)) - nodes[i].pos * (query(tot, 20004) - query(tot, nodes[i].pos))) * nodes[i].value;
		ans += (query(tot, nodes[i].pos - 1) * nodes[i].pos - query(sum, nodes[i].pos - 1)) * nodes[i].value;

		update(sum, nodes[i].pos, -nodes[i].pos);
		update(tot, nodes[i].pos, -1);
	}

	printf("%lld", ans);

	return 0;
}