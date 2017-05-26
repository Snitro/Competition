#include<iostream>
using namespace std;
int add(long long int b,long long int p,long long int t){
	if(p == 2)
		return b*b%t;
	if(p == 1)
		return b%t;
	int k = add(b,p/2,t);
	if(p%2 == 0)
		return k*k%t;
	else{
		return k*k*b%t;
	}
}
int main(){
	long long b,p,k;
	cin>>b>>p>>k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<add(b,p,k);
}
