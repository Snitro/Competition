#include<iostream> 
#include<cstdio>
using namespace std;
int f[105][105];
int ans;
int n,m;//n个珍珠 m次 
void set(int x,int y){ //x比y重 
	f[x][y] = 1;
	f[y][x] = -1;
	for(int a = 1;a <= n;a++){
		if(f[y][a] == 1 && f[x][a] == 0)
			set(x,a);
	}
	for(int a = 1;a <= n;a++){
		if(f[x][a] == -1 && f[a][y] == 0)
			set(a,y);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int x,y;
		cin >> x >> y;
		set(x,y);
		//cout << "asd" << endl;
	}
	int p = (n + 1) / 2;
	int ma,mi;
	/*
	for(int x = 1;x <= n;x++){
		for(int y = 1;y <= n;y++){
			cout << f[x][y] << " ";
		}
		cout << endl;
	}
	*/
	for(int x = 1;x <= n;x++){
		ma = 0;
		mi = 0;
		for(int y = 1;y <= n;y++){
			if(f[x][y] > 0)
				ma += 1;
			else if(f[x][y] < 0)
				mi += 1;
		}
		//cout << x << ":  " << ma << "  " << mi << endl;
		if(ma >= p || mi >= p)
			ans++;
	}
	cout << ans;
}
