#include<iostream>
#include<cstdio>
using namespace std;
int map[55][55];
int f[55][55][55][55];
int ans = 0;
int m,n;//mÐÐnÁÐ
int main(){
	freopen("in.txt","r",stdin);
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
			cin >> map[j][i];
	for(int x1 = 1;x1 <= n;x1++){
		for(int y1 = 1;y1 <= m;y1++){
			for(int x2 = 1;x2 <= n;x2++){
				for(int y2 = 1;y2 <= m;y2++){
					int tx1,tx2,tx3,tx4;
					int ty1,ty2,ty3,ty4;
					tx1 = x1 - 1;
					ty1 = y1;
					tx2 = x1;
					ty2 = y1 - 1;
					tx3 = x2 - 1;
					ty3 = y2;
					tx4 = x2;
					ty4 = y2 - 1;
					if(tx1 != tx3 || ty1 != ty3)
						f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2],f[tx1][ty1][tx3][ty3] + map[x1][y1] + map[x2][y2]);
					if(tx1 != tx4 || ty1 != ty4)
						f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2],f[tx1][ty1][tx4][ty4] + map[x1][y1] + map[x2][y2]);
					if(tx2 != tx3 || ty2 != ty3)
						f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2],f[tx2][ty2][tx3][ty3] + map[x1][y1] + map[x2][y2]);
					if(tx2 != tx4 || ty2 != ty4)
						f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2],f[tx2][ty2][tx4][ty4] + map[x1][y1] + map[x2][y2]);
				}
			}
		}
	}
	cout << f[n][m][n][m];
	return 0;
}
