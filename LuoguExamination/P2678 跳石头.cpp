#include<iostream>
#include<cstdio>
using namespace std;
int l,n,m;
int s[50005],end1;
bool pd(int a){
	int last = 0,end1 = 0;
	for(int i = 0;i <= n;i++){
		if(s[i] - last < a){
			end1++;
			continue;
		}
		last = s[i];
	}
	if(end1 <= m)
		return true;
	return false;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> l >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> s[i];
	s[n] = l;
	int L = 1,R = l,mid;
	while(L <= R){
		mid = (L + R) / 2;
		if(pd(mid)){
			end1 = mid;
			L = mid + 1;
		}else{
			R = mid - 1;
		}
	}
	cout << end1;
}
