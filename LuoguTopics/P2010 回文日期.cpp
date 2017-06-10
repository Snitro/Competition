#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
using namespace std;
int day[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
    freopen("in.txt","r",stdin);
    int f,t;
    cin >> f;
    cin >> t;
    int ans = 0;
	for(int i = f / 10000;i <= t / 10000;i++){
		int y,r;
		y = i % 10 * 10 + i / 10 % 10;
		r = i / 100 % 10 * 10 + i / 1000;
		if(y >= 1 && y <= 12 && r >= 1 &&r <= day[y])
			ans++;
	}
	cout << ans;
}
