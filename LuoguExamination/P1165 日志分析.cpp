#include<iostream>
#include<cstdio>
using namespace std;
int lie[200005],e,n,in;
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf("%d",&in);
		if(in == 0){
			scanf("%d",&lie[e++]);
			lie[e-1] = max(lie[e-2],lie[e-1]);
		}
		else if(in == 1){
			if(e != 0)
				e--;
		}else if(in == 2){
			if(e == 0)
				printf("0\n");
			else {
				printf("%d\n",lie[e-1]);
			}
		}
	}
}
