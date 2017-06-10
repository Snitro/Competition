#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long end,x;
void ans(){
	char str[10000];
	end = 0;
	sprintf(str,"%d",x);
	for(long long i = 1;i <= x;i++){
		sprintf(str,"%d",i);
		for(int a = 0;a < strlen(str);a++){
			if(str[a] == '7'){
				end++;
				break;
			}
		}
	}
	cout << x - end << endl;
}
int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x;
		ans();
	}
}
