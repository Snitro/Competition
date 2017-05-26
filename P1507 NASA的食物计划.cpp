#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int v,m,n;//v最大体积   m最大质量  
int f[405][405]; //f[体积][质量]
struct thing{
	int v;//体积 
	int m;//质量 
	int k;//卡路里 
}t[60];
int main(){
	freopen("in.txt","r",stdin);
	cin >> v >> m;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> t[i].v >> t[i].m >> t[i].k;
	for(int i = 1;i <= n;i++){ // 第i种物品 
		for(int a = v;a >= t[i].v;a--){ // 体积 
			for(int b = m;b >= t[i].m;b--){ // 质量 
				f[a][b] = max(f[a][b],f[a - t[i].v][b - t[i].m] + t[i].k);
			}
		}
	}
	cout << f[v][m];
	return 0;
}

