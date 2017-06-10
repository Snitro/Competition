#include<iostream>
using namespace std;
int n,ave,step,a[100];
int main(){
	cin>>n;
	ave = 0;
	step = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];ave+=a[i];
	}
	ave/=n;
	for(int i = 1;i<=n;i++)a[i]-=ave;
	int i = 0;
	int j = n;
	while(a[i] == 0&&i<n)i++;
	while(a[j] == 0&&j>0)j--;
	while(i<j){
		a[i+1]+=a[i];
		a[i] = 0;
		step++;
		i++;
		while(a[i] == 0&&i<j)i++;
	}
	cout<<step;
}
