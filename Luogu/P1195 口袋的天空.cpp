#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int f[1005];

int n, m, k;

long long ans;

struct Data {
	int a;
	int b;
	int c;
} data[10005];

int getFrom(int a) {
	if (f[a] == a)
		return a;
	return f[a] = getFrom(f[a]);
}

void Union(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

bool check(int a, int b) {
	return getFrom(a) == getFrom(b);
}

bool cmp(Data a, Data b) {
	return a.c < b.c;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &k);
	
	if (k > n) {
		cout << "No Answer";
		return 0;
	}
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &data[i].a, &data[i].b, &data[i].c);
	
	sort(data + 1, data + 1 + m, cmp);
	
	for (int i = 1; i <= m; i++) {
		Data &da = data[i];
		
		if (check(da.a, da.b))
			continue;
		
		Union(da.a, da.b);
		
		n--;
		ans += da.c;
		
		if (n == k) {
			cout << ans;
			return 0;
		}
	}
	
	cout << "No Answer";
	
	return 0;
}
