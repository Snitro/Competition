#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[100005],a,t,n;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a;
		if(a > f[t]){
			f[++t] = a;
			continue;
		}
		else
			*lower_bound(f + 1,f + t + 1,a) = a;
	}
	cout << t;
}
