#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
string data[30];
bool cmp(string a,string b){
	return a + b > b + a;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		cin >> data[i];
	sort(data + 1,data + 1 + n,cmp);
	for(int i = 1;i <= n;i++)
		cout << data[i];
	return 0;
}
