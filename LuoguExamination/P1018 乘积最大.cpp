#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long f[45][60];
string in;
int n,k;//n位数  k个乘号 
long long g[45];
long long cut(int l,int r){
	long long end = 0;
	for(int i = l;i <= r;i++)
		end = end * 10 + g[i];
	return end;
}
int main(){
	cin >> n >> k >> in;
	for(int i = 1;i <= n;i++)
		g[i] = in[i - 1] - '0';
	for(int i=1;i<=n;i++)
        f[i][0] = cut(1,i);
	for(int i = 2;i <= n;i++){ //枚举分割为前i位数字 
		for(int a = 1;a <= min(i-1,k);a++){ //枚举有几个乘号 
			for(int b = a;b < i;b++){ //在第几位放乘号 
				 f[i][a] = max(f[i][a],f[b][a-1] * cut(b + 1,i));
			}
		}
	}
	cout<<f[n][k];
    return 0;
}
