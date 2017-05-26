#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int n,int m){
	return n > m;
}
bool cmp2(int n,int m){
	return n < m;
}
int main(){
	freopen("in.txt","r",stdin);
	int i;
	while(cin >> i){
		if(i == 0)
			return 0;
		int n,tian[1005],wang[1005],end = 0;
		n = i;
		for(int i = 0;i < n;i++)
			cin >> tian[i];
		for(int i = 0;i < n;i++)
			cin >> wang[i];
		sort(tian,tian + n,cmp);
		sort(wang,wang + n,cmp2);
		/*
		for(int i = 0;i < n;i++)
			cout << tian[i] << " ";
		cout << endl;
		for(int i = 0;i < n;i++)
			cout << wang[i] << " ";
		cout << endl;
		cout << endl;
		*/
		bool flg;
		for(int i = 0;i < n;i++){
			flg = true;
			for(int a = n - 1;a >= 0;a--)
				if(tian[a] > wang[i]){
					flg = false;
					tian[a] = -1;
					end++;
					break;
				}
			if(flg){
				for(int a = n - 1;a >= 0;a--)
					if(tian[a] == wang[i]){
						flg = false;
						tian[a] = -1;
						break;
					}
				if(flg)
					end--;
			}
		}
		cout << end * 200 << endl;
	}
}
