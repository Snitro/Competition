#include <iostream> 
#include <cstdio>

using namespace std;

int n, m, p;

int f[5005];

int getFrom(int p) {
	if (p == f[p])
		return p;
	return f[p] = getFrom(f[p]);
}

bool check(int a, int b) {
	return getFrom(a) == getFrom(b);
}

void Union(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &p);
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	int a, b;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		Union(a, b);
	}
	
	for (int i = 1; i <= p; i++) {
		scanf("%d%d", &a, &b);
		if (check(a, b))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
