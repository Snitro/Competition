#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

queue <int> ans;
queue <int> q;

int map[505][505];

bool flg[505];

int h[505];

int du[505];

int n, p;

void setter(int id) {
	for (int i = 1; i <= n; i++)
		if (map[id][i] && !h[i]) {
			if (!flg[i]) {
				h[i] = h[id] + map[id][i];
				flg[i] = true;
				setter(i);
			} else if (h[i] != h[id] + map[id][i]) {
				cout << -1;
				exit(0);
			}
		}
		
	for (int i = 1; i <= n; i++)
		if (map[i][id]) {
			if (!flg[i]) {
				h[i] = h[id] - map[i][id];
				setter(i);
			} else if (h[i] != h[id] - map[i][id]) {
				cout << -1;
				exit(0);
			}
		}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> n >> p;
	
	int a, b, c;
	
	for (int i = 1; i <= p; i++) {
		scanf("%d%d%d", &a, &b, &c);
		map[a][b] = c;
		du[b]++;
	}
	
	int begin = 0;
	
	for (int i = 1; i <= n; i++)
		if (!du[i]) {
			begin = i;
			break;
		}
	
	if (!begin) {
		cout << -1;
		return 0;
	}
	
	h[begin] = 0;
	flg[begin] = true;
	
	setter(begin);
	
	int add = 0;
	
	for (int i = 1; i <= n; i++)
		if (h[i] < 0 && h[i] < add)
			add = h[i];
	
	for (int i = 1; i <= n; i++)
		cout << h[i] - add << endl;
	
	return 0;
}

