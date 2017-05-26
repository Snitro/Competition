#include<iostream>
#include<cstdio>
using namespace std;
int a[100000];
int qsort(int l,int r){
	int i,j,mid,p;
	i = l;
	j = r;
	mid = a[(l + r) / 2];
	do{
		while(a[i] < mid)
			i++;
		while(a[j] > mid)
			j--;
		if(i <= j){
			p = a[i];
			a[i] = a[j];
			a[j] = p;
			i++;
			j--;
		}
	}while(i <= j);
	if(l < j)
		qsort(l,j);
	if(i < r)
		qsort(i,r);
}
int main(){
	int l;
	cin>>l;
	for(int i = 1;i<l+1;i++)
		scanf("%d",&a[i]);
	qsort(1,l);
	for(int i = 1;i<l+1;i++)
		cout<<a[i]<<" ";
}
