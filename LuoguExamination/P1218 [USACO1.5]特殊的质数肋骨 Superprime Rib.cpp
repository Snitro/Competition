#include<iostream>
using namespace std;
int n,e,s[10],flg[4] = {1,3,7,9},flg2[4] = {2,3,5,7};
bool f;
int getc(int x){
	int e = 1;
	for(int a = 0;a<x;a++)
		e*=10;
	return e;
}
bool pd(int x)
{
    if(x==1)
        return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
bool pd(int s[]){
	e = 0;
	for(int a = 0;a<n;a++)
		e+=getc(n-a-1)*s[a];
	for(int a = n-1;a>=0;a--){
		if(!pd(e))
			return false;
		e = (e - s[a])/10;
	}
	return true;
}
void sou(int c,int s[]){
	if(c == n){
		if(pd(s)){
			for(int a = 0;a<n;a++)
				cout<<s[a];
			cout<<endl;
		}
		return;
	}
	for(int a = 0;a<4;a++){
		s[c] = flg[a];
		sou(c+1,s);
	}
}
int main(){
	cin>>n;
	for(int a = 0;a<4;a++){
		s[0] = flg2[a];
		sou(1,s);
	}
}
