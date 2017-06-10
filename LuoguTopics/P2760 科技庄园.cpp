#include<iostream>
#include<cstdio>
#define l long
using namespace std;
l n,m,td,a;//行 列 时间 体力
l map[101][101];
l f[10005];
struct peach{
	l num;//一次摘的个数 
	l ti;//最多摘的次数 
	l td;//单程需要时间 等于 花费的体力 
}peach[10005];
l k = 0;
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m >> td >> a;
	td = min(td,a - 1);
	for(int y = 1;y <= n;y++){
		for(int x = 1;x <= m;x++){
			cin >> map[x][y];
			if(map[x][y]){
				peach[++k].num = map[x][y];
				peach[k].td = (x + y) * 2;
			}
		}
	}
	k = 0;
	for(int y = 1;y <= n;y++){
		for(int x = 1;x <= m;x++){
			cin >> a;
			if(map[x][y])
				peach[++k].ti = a;
		}
	}
	for(int i = 1;i <= k;i++){
		for(int j = td;j >= 1;j--){
			for(int g = 1;g <= peach[i].ti;g++){
				if(j - g * peach[i].td >= 0)
					f[j] = max(f[j] , f[j - g * peach[i].td] + g * peach[i].num);
			}
		}
	}
	cout << f[td];
	return 0;
}
