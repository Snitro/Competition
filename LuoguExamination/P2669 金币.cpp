#include<iostream>
using namespace std;
int k,ans,n = 1;
int main(){
	cin>>k;
	for(int a = 1;a <= k;){
		for(int b = 1;b <= n&&a<=k;b++){
			a++;
			ans += n;
			//cout<<"+"<<n;
		}
		n++;
	}
	//cout<<endl;
	cout<<ans;
}
