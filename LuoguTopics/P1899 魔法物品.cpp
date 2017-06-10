#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
int f[10000005];
int n,p;
int th_len;
struct thing {
	int v;
	int p;
	int t;
}th[1005];
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string in;
	cin >> n >> p;
	getline(cin,in);
	int v = 0,allv = 0,callv;
	for(int i = 1;i <= n;i++){
		stringstream st;
		getline(cin,in);
		st << in;
		int a,b;
		st >> a;
		allv += a;
		if(st >> b && b - a > p){
			th[++th_len].v = a;
			th[th_len].p = b;
			th[th_len].t = b - a - p;
		}else
			v += a;
	}
	callv = allv;
	for(int i = 0;i <= th_len;i++){
		for(int j = 1;j <= allv;j++){
			f[j] = 999999999;
		}
	}
	if(p > v){
		for(int i = 1;i <= th_len;i++){
			for(int j = allv;j >= 1;j--){
				f[j] = f[j];
				if(j - th[i].v>= 0){
					f[j] = min(f[j],f[j - th[i].v] + th[i].t);
				}
			}
		}
		int mi = 999999999;
		for(int i = p - v;i <= allv;i++)
			if(f[i] < mi)
				mi = f[i];
		for(int i = 1;i <= th_len;i++)
			allv += th[i].t;
		if(allv - mi <= 0)
			cout << callv;
		else
			cout << allv - mi;
	}else{
		for(int i = 1;i <= th_len;i++)
			allv += th[i].t;
		cout << allv;
	}
	return 0;
}
