#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int n;
long long ans;
struct cmp{
	bool operator()(const int a,const int b)const{
		return a > b;
	}
};
priority_queue< int ,vector<int>, cmp > pq;
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	int x;
	for(int i = 1;i <= n;i++){
		cin >> x;
		pq.push(x);
	}
	while(pq.size() != 1){
		int a,b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans;
	return 0;
}
