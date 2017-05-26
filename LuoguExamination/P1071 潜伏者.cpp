#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a,b,c;
char f[25];
char t[25];
int main(){
	freopen("in.txt","r",stdin);
	cin >> a >> b >> c;
	if(a.size() < 24 || b.size() < 24){
		cout << "Failed";
		return 0;
	}
	for(int i = 0;i < a.size();i++){
		int id = a[i] - 'A';
		int id2 = b[i] - 'A';
		if(f[id] == 0)
			f[id] = b[i];
		if(t[id2] == 0)
			t[id2] = a[i];
		if(t[id2] != 0 && t[id2] != a[i]){
			cout << "Failed";
			return 0;
		}
		if(f[id] != 0 && f[id] != b[i]){
			cout << "Failed";
			return 0;
		}
	}
	for(int i = 0;i < c.size();i++){
		cout << f[c[i] - 'A'];
	}
	return 0;
}
