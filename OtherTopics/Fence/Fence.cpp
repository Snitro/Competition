#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int map[505][505];
int du[505];
int f;
int ans[1030];
int c = 1;
void dfs(int id){
	for(int i = 1;i < 505;i++){
		if(map[id][i]){
			map[id][i]--;
			map[i][id]--;
			dfs(i);
		}
	}
	ans[c++] = id;
}
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	cin >> f;
	int a,b;
	for(int i = 1;i <= f;i++){
		scanf("%d%d",&a,&b);
		map[a][b]++;
		map[b][a]++;
		du[a]++;
		du[b]++;
	}
	a = 1;
	for(int i = 1;i < 505;i++)
		if(du[i] % 2){
			a = i;
			break;
		}
	dfs(a);
    int tot=1;
    while(ans[tot]!=0)
		tot++;
    tot--;
    for(int i = tot;i >= 1;i--)
        cout << ans[i] << endl;
}
