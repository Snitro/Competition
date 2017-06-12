#include<iostream>
#include<cstdio>
using namespace std;
int n;
bool judge(int i){
	if(i == 0)
		return false;
	for(int a = 2;a * a <= i;a++)
		if(i % a == 0)
			return false;
	return true;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = 2;i <= n;i++)
		if(judge(i))
			for(int j = i;j + i <= n;j++)
				if(judge(j) && judge(n - i - j)){
					cout << i << " " << j << " " << (n - i - j) << endl;
					return 0;
				}
	return 0;
}
