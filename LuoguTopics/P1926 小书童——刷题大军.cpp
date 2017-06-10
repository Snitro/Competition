#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,r;//n个题目   m项作业  k分以上算及格。r个时间
int sub[1000];
int score[1000];
int time[1000];
int F[1000];//F[i][j]表示用前i个物品达到j分需要的最小时间 
bool cmp(int a,int b){
	return a < b;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m >> k >> r;
	for(int i = 1;i <= n;i++)
		cin >> sub[i];
	for(int i = 1;i <= m;i++)
		cin >> time[i];
	for(int i = 1;i <= m;i++)
		cin >> score[i];
	for(int i = 1;i <= k;i++){
		if(score[1] >= i)
			F[i] = time[1];
		else
			F[i] = 9999999;
	}
	for(int i = 2;i <= m;i++){
		for(int f = k;f >= 1;f--){
			int a = F[f];
			if(f - score[i] >= 0)
				a = min(a,F[f - score[i]] + time[i]);
			F[f] = a;
		}
	}
	F[k] = r - F[k];
	int ans = 0;
	sort(sub + 1,sub + 1 + n,cmp);
	for(int i = 1;i <= n;i++){
		F[k] -= sub[i];
		if(F[k] >= 0)
			ans++;
		else{
			cout << ans;
			return 0;
		}
	}
}
