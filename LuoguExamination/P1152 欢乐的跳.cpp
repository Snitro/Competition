#include<iostream>
#include<cstdio>
using namespace std;
int n,p[50000],in1,in2,c;
int main(){
//	freopen("in.txt","r",stdin);
	cin >> n;
	cin>>in1;
	for(int a = 1;a < n;a++){
		cin >> in2;
		c = in2 - in1;
		if(c < 0)
			c = -c;
		p[c]++;
		in1 = in2;
	}
	/*
	for(int a = 1;a <= n-1;a++){
		cout << p[a] << " ";
	}
	*/
	for(int a = 1;a <= n-1;a++){
		if(p[a] == 0){
			cout << "Not jolly";
			return 0;
		}
	}
	cout << "Jolly";
	return 0;
}
