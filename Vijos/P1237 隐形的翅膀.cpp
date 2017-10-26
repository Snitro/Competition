#include <iostream>
#include <cstdio>
#include <algorithm>

#define del 0.6180339887498949

using namespace std;

int n;

struct Data {
	double s;
	double b;
} datas[60005];

bool cmp(Data a, Data b) {
	return a.s < b.s;
}

double abs(double x) {
	if (x < 0)
		return -x;
		
	return x;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &datas[i].s);
		datas[i + n].s = datas[i].s / del;
		datas[i + n].b = datas[i].s;
	}
	
	sort(datas + 1, datas + 1 + 2 * n, cmp);
	
	double b = 99999999999999;
	int ans1 = 0, ans2 = 0;
	
	for (int i = 1; i <= 2 * n; i++) {
		if (datas[i].b) {
			int id = i - 1;
			
			while (datas[id].b && id > 0)
				id--;
			
			if (id >0 && abs(datas[i].b / datas[id].s - del) < b) {
				b = abs(datas[i].b / datas[id].s - del);
				ans1 = datas[i].b;
				ans2 = datas[id].s;
			}
			
			id = i + 1;
			
			while (datas[id].b && id <= 2 * n)
				id++;
				
			if (id <= 2 * n && abs(datas[i].b / datas[id].s - del) < b) {
				b = abs(datas[i].b / datas[id].s - del);
				ans1 = datas[i].b;
				ans2 = datas[id].s;
			}
		}
	}
		
	cout << ans1 << endl << ans2;	
	
	return 0;
}
