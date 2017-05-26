#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
int fx[8] = {0,1,1,1 ,0,-1,-1,-1},
	fy[8] = {1,1,0,-1,-1,-1,0 ,1};
int bs[10000][2];
int mg[105][105];
bool flg[105][105];
int m,n;
void search(int x,int y,int c){
	bs[c][0] = x;
	bs[c][1] = y;
	if(mg[x][y])
		return;
	if(x == n && y == m){
		for(int i = 0;i <= c;i++)
			cout << bs[i][1] << " " << bs[i][0] << endl;
		exit(0);
	}
	//cout << x << " " << y << " " << c << " " << mg[x][y] << endl;
	for(int i = 0;i < 8;i++){
		int zx = x + fx[i];
		int zy = y + fy[i];
	//	if(x == 6 && y == 8)
	//		cout << zx << " " << zy << " " << c << " asdasdasda" << endl;
		if(zx >= 1 && zy >=1 && zx <= n && zy <= m && !flg[zx][zy]){
			flg[zx][zy] = true;
			search(zx,zy,c+1);
			flg[zx][zy] = true;
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
		for(int a = 1;a <= n;a++)
			cin >> mg[a][i];
	flg[1][1] = true;
	search(1,1,0);
	cout << "-1";
}
