#include<iostream>
#include<cstdio>
using namespace std;
int n,m;//nºáĞĞ   mÊúÁĞ 
int tu[100][100];//tu[y][x];
int rem[100][100];
bool flg[100][100];
int fx[4] = {1,0,-1,0};
int fy[4] = {0,-1,0,1};
int search(int x,int y){
	//cout << x << " " << y << endl;
	int zx,zy;
	int big = 1;
	for(int i = 0;i < 4;i++){
		zx = x + fx[i];
		zy = y + fy[i];
		if(zx < 1 || zx > m || zy < 1 || zy > n)
			continue;
		//cout << y << " " << x << "--->" << zy << " " << zx << " " << tu[y][x] << " " <<tu[zy][zx] << endl;
		if(tu[zy][zx] < tu[y][x] && !flg[zy][zx]){
			if(rem[zy][zx] != 0)
				big = max(big,rem[zy][zx] + 1);
			else{
				flg[zy][zx] = true;
				big = max(big,search(zx,zy) + 1);
				flg[zy][zx] = false;
			}
		}
	}
	rem[y][x] = big;
	return big;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	for(int y = 1;y <= n;y++)
		for(int x = 1;x <= m;x++)	
			cin >> tu[y][x];
	for(int y = 1;y <= n;y++)
		for(int x = 1;x <= m;x++)	
			search(x,y);
	int big = 0;
	for(int y = 1;y <= n;y++)
		for(int x = 1;x <= m;x++)	
		big = max(big,rem[y][x]);
	cout << big;
	return 0;
//	search(1,1);
//	search(2,1);
//	search(3,1);
//	search(4,1);
//	search(5,5);
	for(int y = 1;y <= n;y++){
		for(int x = 1;x <= m;x++)	
			cout << rem[y][x] << " ";
		cout << endl;
	}
}
