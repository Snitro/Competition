#include <iostream>
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

int n, m;

int add[50005];
int del[50005];

void add_add(int k, int num) {
	while (k <= n) {
		add[k] += num;
		k += lowbit(k);
	}
}

int add_query(int k) {
	int ans = 0;
	
	while (k) {
		ans += add[k];
		k -= lowbit(k);
	}
	
	return ans;
}

void del_add(int k, int num) {
	while (k <= n) {
		del[k] += num;
		k += lowbit(k);
	}
}

int del_query(int k) {
	int ans = 0;
	
	while (k) {
		ans += del[k];
		k -= lowbit(k);
	}
	
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	int a, b, c;
	
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		
		if (a == 1) {
			add_add(b, 1);
			del_add(c, 1);
		} else
			printf("%d\n", add_query(c) - del_query(b - 1));
	}
	
	return 0;
}
