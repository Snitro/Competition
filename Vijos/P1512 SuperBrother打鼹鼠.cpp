#include <iostream>
#include <cstdio>

#define lowbit(x) x & -x

using namespace std;

int n;

long long tot[1025][1025];

void add(int x, int y, long long num) {
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			tot[i][j] += num;
}

long long query(int x, int y) {
	long long ans = 0;
	
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			ans += tot[i][j];
	
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	int a, b, c, d, e;
	
	while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
		b++;
		c++;
		d++;
		
		if (a == 1) 
			add(b, c, d - 1);
		else if (a == 2) {
			scanf("%d", &e);
			e++;
			
			printf("%lld\n", query(d, e) + query(b - 1, c - 1) - query(b - 1, e) - query(d, c - 1));
		}
	}
	
	return 0;
}
