#include <iostream>
#include <cstdio>

using namespace std;

int m, n, w;

struct Node {
	int value;
	int cost;
} nodes[1000000];

long long f[1000000];

void add(int value, int cost) {
	nodes[++m].value = value;
	nodes[m].cost = cost;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &w);
	
	int a, b, c;
	
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		
		int i = 1;
		
		while (c >= i) {
			add(a * i, b * i);
			c -= i;
			i = i << 1;
		}
		
		if (c)
			add(a * c, b * c);
	}
	
	for (int i = 1; i <= m; i++)
		for (int j = w; j >= nodes[i].cost; j--)
			f[j] = max(f[j], f[j - nodes[i].cost] + nodes[i].value);
			
	cout << f[w];
	
	return 0;
}
