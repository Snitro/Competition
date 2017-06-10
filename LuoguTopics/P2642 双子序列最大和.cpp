#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n;
int data[1000005];
ll ld[1000005];
ll rd[1000005];
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = 1;i <= n;i++)
		scanf("%d",&data[i]);
	ld[1] = data[1];
	for(int i = 2;i <= n;i++)
		if(ld[i - 1] < 0)
			ld[i] = data[i];
		else
			ld[i] = data[i] + ld[i - 1];
	rd[n] = data[n];
	for(int i = n - 1;i >= 1;i--){
		if(rd[i + 1] < 0)
			rd[i] = data[i];
		else
			rd[i] = data[i] + rd[i + 1];
	}
	for(int i = 2;i <= n;i++){
		if(ld[i - 1] > ld[i])
			ld[i] = ld[i - 1];
		if(rd[n - i + 2] > rd[n - i + 1])
			rd[n - i + 1] = rd[n - i + 2];
	}
	ll ma = ld[1] + rd[3];
	for(int i = 3;i < n;i++)
		if(ld[i - 1] + rd[i + 1] > ma)
			ma = ld[i - 1] + rd[i + 1];
	cout << ma;
	return 0;
}
