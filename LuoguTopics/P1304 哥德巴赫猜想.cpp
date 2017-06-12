#include<iostream>
#include<cstdio>
using namespace std;
bool judge(int i){
	for(int a = 2;a * a <= i;a++)
		if(i % a == 0)
			return false;
	return true;
}
void guess(int i){
	for(int a = 2;a <= i / 2;a++)
		if(judge(a) && judge(i - a)){
			cout << i << "=" << a << "+" << i - a << endl;
			return;
		}
}
int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin >> n;
	for(int i = 4;i <= n;i += 2){
		guess(i);
	}
	return 0;
}
