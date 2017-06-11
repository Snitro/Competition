#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int F[55][55][2]; // 0 左  1 右 
int n,c;// n路灯总数   c 当前位置 
struct Light{
	int location;
	int cost;
}light[55];
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> c;
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&light[i].location,&light[i].cost);
		light[i].cost += light[i - 1].cost;
	}
	memset(F,0x7f,sizeof(F));
	F[c][c][0] = F[c][c][1] = 0;
	for(int left = c;left >= 1;left--){
		for(int right = left + 1;right <= n;right++){
			F[left][right][0] = min(F[left + 1][right][0] + (light[n].cost - (light[right].cost -
				light[left].cost)) * (light[left + 1].location - light[left].location),F[left][right][0]);
			F[left][right][0] = min(F[left + 1][right][1] + (light[n].cost - (light[right].cost -
				light[left].cost)) * (light[right].location - light[left].location),F[left][right][0]);
			F[left][right][1] = min(F[left][right - 1][1] + (light[n].cost - (light[right - 1].cost -
				light[left - 1].cost)) * (light[right].location - light[right - 1].location),
				F[left][right][1]);
			F[left][right][1] = min(F[left][right - 1][0] + (light[n].cost - (light[right - 1].cost -
				light[left - 1].cost)) * (light[right].location - light[left].location),F[left][right][1]);
		}
	}
	cout << min(F[1][n][0],F[1][n][1]);
	return 0;
}
