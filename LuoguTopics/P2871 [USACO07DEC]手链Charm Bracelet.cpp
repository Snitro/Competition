#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ans[200005],w[200005][2];//n件物品，容量为m 
int main(){
	//freopen("in.txt","r",stdin);
	cin >> n >> m;
	for(int a = 1;a <= n;a++){
		cin >> w[a][0] >> w[a][1];
	}	
	for(int b = 1;b <= n;b++){
		for(int a = m;a >= w[b][0];a--){
			ans[a] = max(ans[a],ans[a-w[b][0]]+w[b][1]);
		}
		/*
		for(int a = 1;a<=m;a++)
			cout<<ans[a]<<" ";
		cout<<endl;
		*/
		
	}
	/*
 	for(int b = 1;b<=m;b++){
		 for(int a = 1;a<=n;a++){
	 		cout<<ans[b][a]<<"  ";
	 	}
	 	cout<<endl;
	 }
	*/
	cout << ans[m];
}
