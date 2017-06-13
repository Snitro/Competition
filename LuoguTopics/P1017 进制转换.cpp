#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
void gcd(int a,int b,int &d,int &x,int &y){
	if(!b){
		d = a;
		x = 1;
		y = 0;
	}else{
		gcd(b,a % b,d,y,x);
		y -= x * (a / b);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> a >> b;
	int d,x,y;
	gcd(a,b,d,x,y);
	cout << (x + b) % b;
	return 0;
}
