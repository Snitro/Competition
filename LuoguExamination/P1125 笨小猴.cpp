#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string in;
int b,s,i;
bool pd(int i){
	if(i == 0||i == 1)
		return false;
//	cout << i << " ";
	for(int a = 2;a * a <=i;a++)
		if(i == (int)(i / a) * a)
			return false;
	return true;
}
int get(int n){
//	cout << (char)(n+'a'-1) <<" ";
	int e = 0;
	for(int a = 0;a < in.length();a++)
		if(n == in[a] - 'a' + 1)
			e++;
//	cout << e << endl;
	return e;
}
int main(){
//	freopen("in.txt","r",stdin);
	cin >> in;
	for(int a = 1;a <= 26;a++){
		i = get(a);
		if(i != 0){
			b = max(i,b);
			if(s == 0)
				s = i;
			s = min(i,s);
		}
	}
//	cout << b << " " << s << endl;
	if(pd(b - s)){
		cout << "Lucky Word" << endl;
		cout << b - s;
	}else
		cout << "No Answer\n0";
}
