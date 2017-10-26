#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double h,s,v,l,k,n;
void count(double begin,int end){
	int b = begin;
	if(b != begin)
		b++;
 	int ans = min((int)(n-1),(int)end) - max(0,b) + 1;
 	cout << max(0,ans);
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> h >> s >> v >> l >> k >> n;
	double t = (h - k) / 5;
	t = sqrt(t);
	double a = s + l - v * t + 0.0001;
	count(s - v * sqrt(h/5) - 0.0001,a);
	return 0;
}
