#include<iostream>
#include<algorithm>
using namespace std;
int n,in[105],total;
bool pd(int i,int a){
	for(int b = 1;b < i;b++)
		if(in[b] + in[i] == a)
			return true;
	return false;
}
bool pan(int i,int a){
	for(int b = 2;b < i;b++)
		if(pd(b,a))
			return true;
	return false;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> in[i];
	sort(in + 1,in + 1 + n);
	for(int i = 3;i <= n;i++){
		if(pan(i,in[i]))
			total++;
	}
	cout << total;
}
