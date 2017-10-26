#include<iostream>
#include<cstdio>
using namespace std;
int n,m;//n个哨所  m个数据 
int map[105][105];
int main(){
    freopen("in.txt","r",stdin);
    cin >> n >> m;
    int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		    map[i][j]=420000;
		}
	}	
    for(int a = 0;a < m;a++){
        cin >> i >> j >> k;
        map[i][j] = k;
        map[j][i] = k;
    }
    for(k = 1;k <= n;k++){
    	for(i = 1;i <= n;i++)
	        for(j = 1;j <= n;j++){
	            if(map[i][j] > map[i][k] + map[k][j] && map[i][k]!=420000 && map[k][j]!=420000){
	                map[i][j] = map[i][k] + map[k][j];
	            }
	        }
    }
    int b = 0;
    for(j = 1;j <= n;j++)
        if(map[1][j] != 0){
            b = max(b,map[1][j]);
        }
    cout << b;
}
