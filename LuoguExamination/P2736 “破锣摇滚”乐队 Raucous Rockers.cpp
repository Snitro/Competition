#include<iostream>
#include<cstdio>
using namespace std;
int n,t,m;//n首歌   每一张 t 分钟    m 张cd 
int f[405];
int song[25];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> n >> t >> m;
	for(int i = 1;i <= n;i++)
		cin >> song[i];
	for(int i = 1;i <= n;i++) {
		for(int j = t * m;j >= 1;j--){
			f[j] = f[j];
			if(j % t >= song[i])
				f[j] = max(f[j],f[j - song[i]] + 1);
			else if (j / t * t - song[i] >= 0)
				f[j] = max(f[j],f[j / t * t - song[i]] + 1);
		}
	}
	cout << f[t * m];
	return 0;
}
