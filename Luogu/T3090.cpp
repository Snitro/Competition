#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	while(true){
		int c[105];//个数 
		int j[105];//硬币种类 
		bool f[1005];
		bool zh[1005][100];
		int m,n;//n种硬币   不大于m的面值
		memset(c,0,sizeof(c));
		memset(j,0,sizeof(j));
		memset(f,0,sizeof(f));
		memset(zh,0,sizeof(zh));
		cin >> n >> m;
		if(!n && !m)
			return 0;
		f[0] = true;
		for(int i = 1;i <= n;i++)
			cin >> j[i];
		for(int i = 1;i <= n;i++)
			cin >> c[i];
		int a = 0;
		for(int i = 1;i <= n;i++)
			a += j[i] * c[i];
		m = min(m,a);
		for(int i = 1;i <= n;i++){//硬币种类 
			for(int g = 1;g <= c[i];g++){//单个硬币的个数 
				for(int z = m;z >= 1;z--){//凑成的价格 
					if(z - g * j[i] < 0)
						continue;
					if(f[z - g * j[i]]){
						zh[z][g] = true;
						//cout << g << " : " << z  << "     " << z - g * j[i] << endl;
					}
				}
			}
			for(int g = 1;g <= c[i];g++)
				for(int a = 1;a <= m;a++)
					f[a] = f[a] || zh[a][g];
			memset(zh,0,sizeof(zh));
			/*
			for(int g = 1;g <= m;g++)
				cout << f[g] << " ";
			cout << endl;
			*/
		}
		int ans = 0;
		for(int z = 1;z <= m;z++)	
			if(f[z])
				ans++;
		cout << ans << endl;
	}
}
