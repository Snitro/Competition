#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n;

bool p[5005];

double dist[5005];

double ans;

struct position {
	int x;
	int y;
} pos[5005];

double getValue(int a, int b) {
	return sqrt((double)(pos[a].x - pos[b].x) * (pos[a].x - pos[b].x) + (double)(pos[a].y - pos[b].y) * (pos[a].y - pos[b].y));
}

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &pos[i].x, &pos[i].y);
	
	for (int i = 1; i <= n; i++)
		dist[i] = 1e8;
	
	dist[1] = 0;

	int MIN;
	double value;

	for (int i = 1; i <= n; i++) {
		value = 1e8;
		
		for (int j = 1; j <= n; j++)
			if(!p[j] && dist[j] < value) {
				value = dist[j];
				MIN = j;
			}
				
		p[MIN] = true;
		ans += value;
		
		for (int j = 1; j <= n; j++)
			if (getValue(MIN, j) < dist[j])
				dist[j] = getValue(MIN, j);
	}
	
	printf("%.2lf", ans);
	
	return 0;
}
