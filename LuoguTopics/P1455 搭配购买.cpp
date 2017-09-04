#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int n, m, w;

map <int, int> M;

int f[10005];

int F[5005];

int len;

struct thing {
	int v;
	int w;
} things[10005], t[10005];

int getFrom(int x) {
	if (x == f[x])
		return x;
	
	return f[x] = getFrom(f[x]);
}

void Union(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

bool query(int a, int b) {
	return getFrom(a) == getFrom(b);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &w);
	
	for (int i = 1; i <= n; i++) 
		f[i] = i;
	
	for (int i = 1; i <= n; i++) 
		scanf("%d%d", &things[i].v, &things[i].w);
		
	int a, b;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		
		Union(a, b);
	}
	
	for (int i = 1; i <= n; i++) {
		int id;
		
		if (M[getFrom(i)])
			id = M[getFrom(i)];
		else {
			id = ++len;
			M[getFrom(i)] = id;
		}
		
		t[id].v += things[i].v;
		t[id].w += things[i].w;
	}
	
	for (int i = 1; i <= len; i++)
		for (int j = w; j >= t[i].v; j--)
			F[j] = max(F[j], F[j - t[i].v] + t[i].w);
	
	printf("%d", F[w]);
	
	return 0;
}
