#include<iostream>
#include<cmath>
using namespace std;
long long int n,k,t[100000];
int main(){
	cin>>n>>k;
	t[1] = 1;
	for(int a = 2;a<=k;a++){
		t[a] = 2*t[a-1];
		t[a]%=100003;
	}
	for(int a = k+1;a<=n;a++){
		for(int b = 1;b<=k;b++){
			t[a]+=t[a-b];
			t[a]%=100003;
		}
	}
	cout<<t[n];
}
