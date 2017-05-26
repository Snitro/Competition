#include<cstdio>  
#include<iostream>  
#include<algorithm> 
using namespace std;
int n;
struct in{
	int in;  
	int id;  
}all[1000001];
bool cmp(const in a,const in b)  
{  
    if (a.in<b.in) return true;  
    else return false;  
}    
int main(){
	cin>>n;
	for(int a = 0;a < n;a++){
		cin>>all[a].in;
		all[a].id = a;
	}
	sort(all,all+n,cmp);
	double end = 0;
	for(int a = 0;a<n;a++){
		cout<<all[a].id+1<<" ";
	}
	for(int a = 0;a<n;a++){
		for(int b = 0;b<a;b++){
			end += all[b].in;
		}
	}
	cout<<endl;
	printf("%.2f",end/n);
}
