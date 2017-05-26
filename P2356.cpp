#include<iostream>
#include<cstdio>
using namespace std;
int n,pa[1005][1005],po[10005][2],pi = 0,end;
bool flg = true;
int main(){
	//freopen("in.txt","r",stdin);
	cin>>n;
	for(int y = 1;y <= n;y++){
		for(int x = 1;x <= n;x++){
			cin>>pa[x][y];
			if(!pa[x][y]){
				flg = false;
				po[++pi][0] = x;
				po[pi][1] = y;
			}
		}
	}
	if(flg){
		cout << "Bad Game!";
		return 0;
	}
	int tend;
	for(int a = 1;a <= pi;a++){
		tend = 0;
		for(int b = 1;b <= n;b++){
			if(pa[b][po[a][1]])
				tend += pa[b][po[a][1]];
			if(pa[po[a][0]][b])
				tend += pa[po[a][0]][b];
		}
		end = max(tend,end);
	}
	cout<<end;
}
