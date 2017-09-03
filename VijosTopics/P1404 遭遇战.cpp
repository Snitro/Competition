#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, s, e;

long long f[90005];

long long No_Ans;

struct Node {
	int begin;
	int end;
	int v;
} nodes[10005];

bool cmp(Node a, Node b) {
	if (a.begin == b.begin)
		return a.end < b.end;
		
	return a.begin < b.begin;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &s, &e);
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &nodes[i].begin, &nodes[i].end, &nodes[i].v);
	
	e = e - s;
	
	for (int i = 1; i <= n; i++) {
		nodes[i].end -= s;
		nodes[i].begin -= s;
		
		if (nodes[i].begin < 0)
			nodes[i].begin = 0;
	}
	
	s = 0;
	
	sort(nodes + 1, nodes + 1 + n, cmp);
	memset(f, 0x7f, sizeof(f));
	
	No_Ans = f[1];
	
	f[0] = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = nodes[i].end; j >= nodes[i].begin; j--)
			f[j] = min(f[j], f[nodes[i].begin - 1] + nodes[i].v);
	
	cout << (f[e] != No_Ans ? f[e] : -1);
	
	return 0;
}
