#include<iostream>
using namespace std;
int n,x,y;
int main(){
	cin>>n;
	if(n == 1){
		cout << "1/1";
		return 0;
	}	
	for(int a = 1;;a++){
		n -= a;
		if(n <= 0){
			n += a;
			if(a % 2 == 0){
				x = a + 1 - n;
				y = n;
			}else{
				x = n;
				y = a + 1 - n;
			}
			cout << y << "/" << x;
			return 0;
		}
	}
}
