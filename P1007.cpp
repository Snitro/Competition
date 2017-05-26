#include<iostream>
#include<cstdio>
using namespace std;
int l,n,max1,min1;
int main(){
	//freopen("in.txt","r",stdin);
	cin >> l >> n;
	int w;
	for(int i = 1;i <= n;i++){
		cin >> w;
		if(w <= (l + 1) / 2){
			max1 = max(max1,l + 1 - w);
			min1 = max(min1,w);
		}else{
			max1 = max(max1,w);
			min1 = max(min1,l + 1 - w);
		}
		//cout << min1 << " " << max1 << endl;
	}
	cout << min1 << " " << max1;
}
