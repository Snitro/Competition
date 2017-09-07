#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

int f[100005];
int s[100005];

bool search(int x) {
	int l = 1, r = m;
	int mid;
	
	while (l < r) {
		mid = (l + r) >> 1;
		
		if (s[mid] == x)
			return true;
			
		if (s[mid] < x)
			l = mid + 1;
			
		if (x < s[mid])
			r = mid;
	}
	
	return s[l] == x;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i]);
		
	for (int i = 1; i <= m; i++)
		scanf("%d", &s[i]);
		
	sort(s + 1, s + 1 + m);
	
	for (int i = 1; i <= n; i++)
		if (search(f[i]))
			printf("%d ", f[i]);
	
	return 0;
}
