#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int x,n,c = 0,l;
	char s[100];
	cin>>x>>n;
	for(int a = x;a <= n;a++){
		sprintf(s,"%d",a);
		l = strlen(s);
		for(int b = 0;b<l;b++){
			if(s[b]-48 == 2)
				c++;
		}
	}
	cout<<c;
}
