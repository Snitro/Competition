#include<iostream>
using namespace std;
long long  n,k,d,y;
bool flg = false;
int main(){
	cin >> n >> k;
	d = n;
	y = n;
	n = 0;
	while(true){
		n = d / k;
		y += n;
		d = d % k + n;
		if(d < k){
			cout << y;
			return 0;
		}
	}
}
