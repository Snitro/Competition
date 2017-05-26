#include<iostream>
#include<cstdio>
using namespace std;
int v,n;
int f[20001];
int vi[31];
int main(){
    freopen("in.txt","r",stdin);
    cin >> v >> n;
    for(int i = 0;i < n;i++){
        cin >> vi[i];
	}
    for(int i = 0;i < n;i++){
    	for(int j = v;j >= vi[i];j--)
            f[j] = max(f[j],f[j - vi[i]] + vi[i]);
    }
    cout << v - f[v];
}

