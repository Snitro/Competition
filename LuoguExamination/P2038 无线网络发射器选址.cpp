#include<iostream>
#include<cstdio>
using namespace std;
int d;
int n;
int ans;
int ansj;
struct data {
	int x;
	int y;
	int k;
} data[25];
int abs(int n) {
	if(n < 0)
		return -n;
	return n;
}
int main() {
	freopen("in.txt","r",stdin);
	cin >> d >> n;
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d",&data[i].x,&data[i].y,&data[i].k);
	for(int x = 0; x <= 128; x++) {
		for(int y = 0; y <= 128; y++) {
			int ta = 0;
			for(int i = 1; i <= n; i++) {
				if(abs(x - data[i].x) <= d && abs(y - data[i].y) <= d)
					ta += data[i].k;
			}
			if(ta == ans)
				ansj++;
			else if(ta > ans) {
				ansj = 1;
				ans = ta;
			}
		}
	}
	cout << ansj << " " << ans;
	return 0;
}
