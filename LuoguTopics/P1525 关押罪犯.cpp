#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

int f[40005];

int b[40005]; //²¹¼¯ 

struct Data {
	int a;
	int b;
	int c;
}data[200000];

int getFrom(int i) {
	if (f[i] == i)
		return i;
	return f[i] = getFrom(f[i]);
}

void Union(int a, int b) {
	f[getFrom(a)] = getFrom(b);
}

bool check(int a, int b) {
	return getFrom(a) == getFrom(b);
}

bool cmp(Data a, Data b) {
	return a.c > b.c;
}

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	for (int i = 1; i <= m; i ++)
		scanf("%d%d%d", &data[i].a, &data[i].b, &data[i].c);
		
	sort(data + 1, data + 1 + m, cmp);
	
	int A, B, C;
	
	for (int i = 1; i <= m; i++) {
		
		if (check(data[i].a, data[i].b)) {
			cout << data[i].c;
			return 0;
		}
		
		A = data[i].a;
		B = data[i].b;
		C = data[i].c;
		
		if (!b[A])
			b[A] = B;
		else
			Union(b[A], B);
			
		if (!b[B])
			b[B] = A;
		else
			Union(b[B], A);	
	}
	
	cout << 0;
	
	return 0;
}
