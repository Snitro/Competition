#include<iostream>
#include<cstdlib>
using namespace std;
int dp[101];
int ans = -1;
struct stor{
    int w;
    int c;
    int g;
} ha[100000];
int main(){
	int v,n;
	cin>>v>>n;
	for(int i = 0;i < n;i++) 
		cin>>ha[i].w>>ha[i].c>>ha[i].g;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<ha[i].g;j++)
			for(int k = v;k>=ha[i].w;k--){
				dp[k]=max(dp[k],dp[k-ha[i].w]+ha[i].c);
			}
	return 0;
}
