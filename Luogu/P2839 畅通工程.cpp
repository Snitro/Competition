#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int f[1005];

int getFrom(int x) {
	if (x == f[x])
		return x;
	return f[x] = getFrom(f[x]);
}

void merge(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	int a, b;
		
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		
		merge(a, b);
	}
	
	int ans = -1;
	
	for (int i = 1; i <= n; i++)
		if (getFrom(i) == i)
			ans++;
		
	cout << ans;
		
	return 0;
}
