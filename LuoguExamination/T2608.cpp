#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
int fx[5] = {0, 1, 2, 2, 1},
	fy[5] = {0,-2,-1, 1, 2};
int en[150][150];
int m,n;//mºá×ø±ê  n×Ý×ø±ê 
int zx,zy;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> m >> n;
	en[m][n] = 1;
	for(int x = m - 1;x >= 1;x--){
		for(int y = n;y >= 1;y--){
			for(int i = 1;i <= 4;i++){
				zx = x + fx[i];
				zy = y + fy[i];
				if(zx <= m && zy <= n && zx >= 1 && zy >= 1)
					if(en[zx][zy] != 0){
						en[x][y] = i;
						break;
					}
			}
		}
	}
	/*
	for(int y = n;y >= 1;y--){
		for(int x = 1;x <= m;x++)
			cout << en[x][y] << " ";
		cout << endl;
	}
	*/
	if(en[1][1] == 0){
		cout << -1;
		return 0;
	}
	int i;
	zx = 1;
	zy = 1;
	while(zx != m || zy != n){
		i = en[zx][zy];
		cout << i << " ";
		zx = zx + fx[i];
		zy = zy + fy[i];
	}
	return 0;
}
