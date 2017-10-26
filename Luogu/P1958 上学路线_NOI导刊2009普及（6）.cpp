#include<iostream>
#include<cstdio>
using namespace std;
int a,b,n;
int p[20][20],z[50][2];
int main(){
//	freopen("in.txt","r",stdin);
	cin >> a >> b >> n;
	for(int i = 1;i <= n;i++)
		cin >> z[i][0] >> z[i][1];
		p[0][1] = 1;
	bool flg = false;
	for(int x = 1;x <= a;x++){
		for(int y = 1;y <= b;y++){
			p[x][y] = p[x-1][y]+p[x][y-1];
			for(int i = 1;i <= n;i++)
				if(z[i][0] == x&&z[i][1] == y){
					p[x][y] = 0;
					break;
				}
		}
	}
	/*
	for(int y = b;y >= 1;y--){
		for(int x = 1;x <= a;x++){
			cout<<p[x][y]<<" ";
		}
		cout<<endl;
	}
	*/
	cout<<p[a][b];
}
