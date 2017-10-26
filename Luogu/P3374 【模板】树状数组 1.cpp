#include <iostream>
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

int n, m;

int tree[500005];

void add(int k, int num) {
	while (k <= n) {
		tree[k] += num;
		k += lowbit(k);
	}
}

int query(int k) {
	int num = 0;
	
	while (k) {
		num += tree[k];
		k -= lowbit(k);
	}
	
	return num;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int a, b, c;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		
		add(i, a);
	}
	
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		
		if (a == 1) 
			add(b ,c);
		else
			printf("%d\n", query(c) - query(b - 1));
	}
	
	return 0;
}
