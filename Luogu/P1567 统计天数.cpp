#include<iostream>
using namespace std;
int in,end,get,last,te = 0;
int main(){
	cin>>in;
	for(int a = 0;a<in;a++){
		cin>>get;
		if(get>last){
			last = get;
			te++;
		}
		else {
			if(te>end)
				end = te;
			te = 1;
			last = get;
		}
	}
	cout<<end;
}
