#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int map[1005][1005];
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	int a,b;
	for(int i = 0;i < m;i++){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int du = 0;
		for(int y = 0;y <= n;y++){
			if(map[i][y])
				du++;
		}
		if(du % 2 == 1)
			ans++;
	}
	if(ans)
		cout << ans / 2;
	else
		cout << 1;
}
