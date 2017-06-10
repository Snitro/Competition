#include<iostream>
#include<cstdio>
using namespace std;
int n;
int flower[100005];
int up,low;
int uplen,lowlen;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&flower[i]);
	up = low = flower[1];
	uplen = lowlen = 1;
	for(int i = 2;i <= n;i++){
		if(uplen % 2 == 0){
			if(flower[i] < up){
				uplen++;
				up = flower[i];
			}else if(flower[i] > up)
				up = flower[i];
		}else{
			if(flower[i] > up){
				uplen++;
				up = flower[i];
			}else if(flower[i] < up)
				up = flower[i];
		}
		if(lowlen % 2 == 0){
			if(flower[i] > low){
				lowlen++;
				low = flower[i];
			}else if(flower[i] < low)
				low = flower[i];
		}else{
			if(flower[i] < low){
				lowlen++;
				low = flower[i];
			}else if(flower[i] > low)
				low = flower[i];
		}
	}
	cout << max(uplen,lowlen);
	return 0;
}
