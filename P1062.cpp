#include<iostream>
#include<cmath>
using namespace std;
long long f[10000];
long long flg = 1;//当前已经乘到k的n次方 
int k,n;
int main(){
	cin >> k >> n;
	f[1] = 1;
	for(int i = 2;i <= n;i++){
		f[i] = pow(k,flg);
		//cout << i << " == " << k << " ^ " << flg << endl;
		flg++;
		int b = i;
		i++;
		for(int a = 1;a < b && i <= n;a++){
			//cout << i << " == " << a << " + "  << b <<endl;
			f[i] = f[a] + f[b];
			i++;
		}
		i--;
	}
	cout << f[n];
}
