#include<iostream>
#include<cstdio>

using namespace std;

int n,i,j;
long long raise[30005];

int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> i >> j;
	for (int x = 3; x <= n; x++)
		raise[x] = 4 * (x - 1);
	if (n % 2) {
		int lx = (n + 1) / 2,rx = lx,uy = lx,dy = lx,flg = 1;
		while (!(j <= rx && j >= lx && i >= uy && i <= dy)) {
			lx--;
			rx++;
			uy--;
			dy++;
			flg++;
		}
		flg = (n + 1) / 2 - flg + 1;
		long long first = 1;
		for (int x = 1; x < flg; x++)
			first += raise[n - (x - 1) * 2];
		int x = flg,y = flg;
		int add = n - (flg - 1) * 2 - 1;
		if (i == y) {
			cout << (first + (j - y));
			return 0;
		} else if (j == x) {
			cout << (first + add * 4 - 1 - (i - y - 1));
			return 0;
		} else {
			first += add;
			x += add;
			if (x == j) {
				cout << (first + (i - y));
				return 0;
			} else {
				cout << (first + 2 * add - (j - flg));
				return 0;
			}
		}
	} else {
		int lx = n / 2,rx = lx + 1,uy = lx,dy = rx,flg = 1;
		while (!(j <= rx && j >= lx && i >= uy && i <= dy)) {
			lx--;
			rx++;
			uy--;
			dy++;
			flg++;
		}
		flg = n / 2 - flg + 1;
		long long first = 1;
		for (int x = 1; x < flg; x++)
			first += raise[n - (x - 1) * 2];
		int x = flg,y = flg;
		int add = n - (flg - 1) * 2 - 1;
		if (i == y) {
			cout << (first + (j - y));
			return 0;
		} else if (j == x) {
			cout << (first + add * 4 - 1 - (i - y - 1));
			return 0;
		} else {
			first += add;
			x += add;
			if (x == j) {
				cout << (first + (i - y));
				return 0;
			} else {
				cout << (first + 2 * add - (j - flg));
				return 0;
			}
		}
	}
	return 0;
}
