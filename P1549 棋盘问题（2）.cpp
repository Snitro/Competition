#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
bool flg[105];
int map[105][105];
bool judge(int n){
    for(int i = 2;i <= n / 2;i++)
        if(n % i == 0)
            return false;
    return true;
}
void dfs(int x,int y){
	/*
	for(int y = 1;y <= n;y++){
		for(int x = 1;x <= n;x++){
			cout << map[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	if(x == n && y == n){
		for(int y = 1;y <= n;y++){
			for(int x = 1;x <= n;x++){
				cout << map[x][y] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	int tx,ty;
	if(x == 1 && y != 1 && y <= n){
		if(y < n){
			tx = 1;
			ty = y + 1;
		}else{
			tx = 2;
			ty = 2;
		}
	}else if(x < n){
		tx = x + 1;
		ty = y;
	}else if( x == n && y == 1){
		tx = 1;
		ty = 2;
	}else{
		tx = 2;
		ty = y + 1;
	}
	for(int i = 2;i <= n * n;i++){
		bool f = true;
		if(map[tx - 1][ty] != 0)
			f = judge(map[tx - 1][ty] + i) && f;
		if(map[tx + 1][ty] != 0)
			f = judge(map[tx + 1][ty] + i) && f;
		if(map[tx][ty - 1] != 0)
			f = judge(map[tx][ty - 1] + i) && f;
		if(map[tx][ty + 1] != 0)
			f = judge(map[tx][ty + 1] + i) && f;
		if(!flg[i] && f){
			flg[i] = true;
			map[tx][ty] = i;
			dfs(tx,ty);
			flg[i] = false;
			map[tx][ty] = 0;
		}
	}
}
//题目存在问题，会存在多解的情况，所以代码不能满分通过 
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	if(n == 1){
		cout << "NO";
		return 0;
	}
	map[1][1] = 1;
	flg[1] = true;
	dfs(1,1);
	cout << "NO";
	return 0;
}
