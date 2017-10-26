#include<iostream>
#include<cstdio>
using namespace std;
int h,n,i,v[510],ans[510][45010],a1,a2;
int main(){
	//freopen("in.txt","r",stdin);
	cin >> h >> n;
	for(i = 1;i <= n;i++)
		cin>>v[i];
	for(int b = 1;b <= h;b++){
		for(int a = 1;a <= n;a++){
			a1 = ans[a-1][b];
			if(b-v[a]>=0)
				a2 = ans[a-1][b-v[a]]+v[a];
			else
				a2 = 0;
			ans[a][b] = max(a1,a2);
		}		
	}
	/*
	for(int b = 1;b <= h;b++){
		cout<<b<<"   ";
		for(int a = 1;a <= n;a++){
			cout<<ans[a][b]<<" ";
		}
		cout<<endl;		
	}
	*/
	cout<<ans[n][h];
}
