#include <iostream>
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

int tree[100005];

int n, m;

void add(int k, int add) {
	while (k <= n) {
		tree[k] += add;
		k += lowbit(k);
	}
}

int query(int k) {
	int sum = 0;
	
	while (k) {
		sum += tree[k];
		k -= lowbit(k);
	}
	
	return sum;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> n >> m;
	
	string data;
	int a, b;
	
	while (m--) {
		cin >> data >> a >> b;
		
		if (data[0] == 'x')
			add(a, b);
		else
			cout << (query(b) - query(a - 1)) << endl;
	}
	
	return 0;
}
