#include<iostream>
#include<cstdio>
using namespace std;
int n,m;//n 人数   m 水龙头 
int time[10005];
long long ans[105];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	int id,v;
	for(int i =1;i <= n;i++){
		int t;
		cin >> t;
		v = ans[1];
		id = 1;
		for(int x = 2;x <= m;x++)
			if(ans[x] < v){
				v = ans[x];
				id = x;
			}
		ans[id] += t;
	}
	int a = ans[1];
	for(int i = 2;i <= m;i++)
		if(ans[i] > a)
			a = ans[i];
	cout << a;
	return 0;
}
