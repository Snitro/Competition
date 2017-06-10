#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int s,t,w;/*s为最小的字母的序号
			t为最大的字母的序号
			w为数字的位数*/
int n; //有n个数 
char p[30];
int ans[30];

void get_next(){
	if(ans[w] + 1 <= n){
		//cout << "c1" << endl;
		ans[w]++;
		return;
	}
	for(int i = w - 1;i >= 1;i--){
		//cout << ans[w]  << "    " << (n - (w - i) - 1) << "   " << (ans[i] <= n - (w - i) - 1) << endl;
		if(ans[i] <= n - (w - i) - 1){
		//	cout << "c" << endl;
			ans[i]++;
			for(int id = i + 1;id <= w;id++){
				ans[id] = ans[id - 1] + 1;
			}
			return;
		}
	}
	exit(0);
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> s >> t >> w;
	n = t - s + 1;
	for(int i = 1;i <= n;i++)
		p[i] = s + i - 2 + 'a';
	char in;
	for(int i = 1;i <= w;i++){
		cin >> in;
		for(int id = 1;id <= n;id++)
			if(p[id] == in){
				ans[i] = id;
				break;
			}
	}
	for(int i = 1;i <= 5;i++){
		get_next();
		for(int a = 1;a <= w;a++)
			cout << p[ans[a]];
		cout << endl;
	}
}
