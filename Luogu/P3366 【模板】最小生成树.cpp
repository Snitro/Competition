#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

long long ans;

int f[5005];

struct Edge{
	int from;
	int to;
	int value;
} edges[200005];

int getFrom(int a) {
	if (a == f[a])
		return a;
	return f[a] = getFrom(f[a]);
}

void Union(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

bool cmp(Edge a, Edge b) {
	return a.value < b.value;
}

bool check(int a, int b) {
	return getFrom(a) == getFrom(b);
}

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].value);
	
	sort(edges + 1, edges + 1 + m, cmp);
	
	for (int i = 1; i <= m; i++) {
		if (!check(edges[i].from, edges[i].to)) {
			Union(edges[i].from, edges[i].to);
			ans += edges[i].value;
		}
	}
	
	for (int i = 2; i <= n; i++)
		if (!check(1, i)) {
			cout << "orz";
			return 0;
		}
	
	cout << ans;
	
	return 0;
}
