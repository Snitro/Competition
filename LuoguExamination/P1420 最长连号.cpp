#include<iostream>
using namespace std;
int all[200],in,end;
int main(){
	cin>>in;
	for(int a = 0;a<in;a++)
		cin>>all[a];
	for(int a = 0;a<in-1;a++){
		int te = 1;
		for(int b = a+1;b<in;b++){
			if(all[b] == all[b-1]+1)
				te++;
			else 
				break;
		}
		if(te>end)
			end = te;
	}
	cout<<end;
}
