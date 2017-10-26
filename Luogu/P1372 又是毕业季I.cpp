#include<iostream>
#include<cstdio>
using namespace std;
/*
从 n 个数中选出 k 个数，使他们的最大公约数最大。
当两个数存在倍数关系的时候最大公约数为较小的那一个数
那么 n / k 便是anser 
*/
int main(){
	//freopen("in.txt","r",stdin);
	int a, b;
	cin >> a >> b;
	cout << a / b;
	return 0;
}
