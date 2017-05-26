#include<iostream>
#include<cstdio>
using namespace std;
int n,m,e[100][1000];
int main(){
	cin>>n>>m;
	for(int a = 1;a<=n;a++){
		e[1][a] = 1;
	}
	for(int h = 2;h<=m;h++){
		for(int l = 1;l<=n;l++){
			e[h][l] = e[h-1][l-1]+e[h][l-h];
		}
	}
	cout<<e[m][n];
}
