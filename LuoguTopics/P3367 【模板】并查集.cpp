#include <iostream>
#include <cstdio>

using namespace std;

int f[10005];

int n, m;

int getFrom (int p) {
	if (f[p] == p)
		return p;
	else 
		return f[p] = getFrom(f[p]);
}

void Union (int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
		
	int z, x ,y;
	int fx, fy;
	
	for (int i = 1; i <= m ; i++) {
		scanf("%d%d%d", &z, &x, &y);
		
		if (z == 1)
			Union(x, y);
		
		if (z == 2) {
			fx = getFrom(x);
			fy = getFrom(y);
			if (fx == fy) 
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	
	return 0;
}
