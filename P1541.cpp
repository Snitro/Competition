#include<iostream>
#include<cstdio>
using namespace std;
int n,m;//N棋盘格子数    m爬行卡片数。
int lu[350];
int pian[5];
int dp[41][41][41][41];
int main(){
	freopen("tortoise.in","r",stdin);
	freopen("tortoise.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> lu[i];
	int x;
	for(int i = 0;i < m;i++){
		cin >> x;
		pian[x] ++ ;
	}
	for(int i = 0;i <= pian[1];i++)
        for(int j = 0;j <= pian[2];j++)
            for(int k = 0;k <= pian[3];k++)
                for(int l = 0;l <= pian[4];l++)
                {
                    if(i) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]);
                    if(j) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]);
                    if(k) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]);
                    if(l) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]);           
                    dp[i][j][k][l]+=lu[i+j*2+k*3+l*4+1];
                }
    cout<<dp[pian[1]][pian[2]][pian[3]][pian[4]];
    return 0;
}
