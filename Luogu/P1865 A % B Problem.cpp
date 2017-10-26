#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool su[1000005];
int ans[1000005];
int n,m;
void maker(){
	int e = sqrt(m + 0.5);
	for(int i = 2;i <= e;i++)
		if(!su[i])
			for(int j = i * i;j <= m;j += i)
				su[j] = true;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	maker();
	su[1] = true;
	for(int i = 1;i <= m;i++)
		ans[i] = ans[i - 1] + !su[i];
	//使用前缀和!!!!!!! 
	int l,r;
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&l,&r);
		if(l < 1 || r > m){
			printf("Crossing the line\n");
			continue;
		}else{
			printf("%d\n",ans[r] - ans[l] + !su[l]);
		}
	}
	return 0;
}
