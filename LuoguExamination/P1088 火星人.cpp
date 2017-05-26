#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;//n手指个数 m整数 
int b[10005];
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		scanf("%d",&b[i]);
	for(int i = 0;i < m;i++)
		next_permutation(b,b + n);
	for(int i = 0;i < n;i++)
		printf("%d ",b[i]);
}
