#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int F[155], n;

int getFrom(int x) {
	if (x == F[x])
		return x;
	return F[x] = getFrom(F[x]);
}

void merge(int a, int b) {
	F[getFrom(a)] = getFrom(b);
}

struct Position {
	int x;
	int y;
} pos[155];

double count(int a, int b) {
	return sqrt((long long)(pos[a].x - pos[b].x) * (pos[a].x - pos[b].x) + (long long)(pos[a].y - pos[b].y) * (pos[a].y - pos[b].y));
}

double f[155][155], fast[155];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		F[i] = i;
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &pos[i].x, &pos[i].y);
		
	char temp[300];
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				f[i][j] = f[j][i] = 999999999999999;
	
	double MAX = 0;
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", &temp[1]);
		
		for (int j = 1; j <= n; j++) {
			if (temp[j] == '1') {
				merge(i, j);
				f[i][j] = f[j][i] = count(i, j);
			}
		}
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[i][k] + f[k][j];
			}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (getFrom(i) == getFrom(j))
				fast[i] = max(fast[i], f[i][j]);
	}
	
	double ans = 999999999999999, t;

	for (int i = 1; i <= n; i++) {
		MAX = max(MAX, fast[i]);
		for (int j = 1; j <= n; j++)
			if (getFrom(i) != getFrom(j)) {
				t = count(i, j) + fast[i] + fast[j];
				if (t < ans)
					ans = t;
			}
	}
	
	printf("%.6f", max(MAX, ans));
		
	return 0;
}
