#include<iostream>
#include<cstdio>
using namespace std;
int m,n;//m竞赛的时间     n题目数目。
int f[10000];
struct text{
	int s;
	int t;
}t[10000];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> m >> n;
	for(int i = 1;i <= n;i++)
		cin >> t[i].s >> t[i].t;
	for(int i = 1;i <= n;i++){
		for(int q = t[i].t;q <= m;q++){
			f[q] = max(f[q],t[i].s + f[q - t[i].t]);
		}
		/*
		for(int q = 1;q <= m;q++)
			cout << q << ":" << f[q] << "     ";
		cout << endl;
		*/
	}
	cout << f[m];
}
