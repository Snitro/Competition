#include<iostream>
using namespace std;
long long in[3],amin,amax;
void common(long long x,long long y){
	long long m = x,n = y,r;
	do{
		r = m%n;
		m = n;
		n = r;
	}while(r!=0);
	x/=m;
	y/=m;
	cout<<x<<"/"<<y;
}
int main(){
	for(int a = 0;a<3;a++)
		cin>>in[a];
	amin = in[0];
	for(int a = 1;a<3;a++)
		if(in[a]<amin)
			amin = in[a];
	amax = in[0];
	for(int a = 1;a<3;a++)
		if(in[a]>amax)
			amax = in[a];
	common(amin,amax);
}
