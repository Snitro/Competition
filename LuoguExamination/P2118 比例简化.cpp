#include<cstdio>
#include<iostream>
using namespace std;
int m,n,l;  //  m/n   <l;
double juedui(double a){
	if(a < 0)
		return 0 - a;
	else
		return a;
}
int gcd(int x, int y){
	if(y == 0) 
		return x;    
	if(x < y)
		return gcd(y,x);    
	else
		return gcd(y, x%y); 
} 
int main(){
	 freopen("in.txt","r",stdin);
	 scanf("%d%d%d",&m,&n,&l);
	 double bz = (m + 0.0) / n;
	 double ch = 10000;
	 int tz,tm;
	 for(double fm = 1;fm <= l;fm++){
	 	for(double fz = 1;fz <= l;fz++){
	 		if(juedui(bz - fz / fm ) <= ch && bz - fz / fm  <= 0){
	 			tz = fz;
	 			tm = fm;
	 			ch = juedui(bz - fz / fm );
	 		} 
	 	}
	 }
	 cout << tz / gcd(tz,tm) << " " << tm / gcd(tz,tm);
}
