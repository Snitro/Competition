#include<cstdio>
#include<iostream>
#include<sstream>
using namespace std;
long long F[205][205];
int data[205];
int in[205];
int n;
int getEnd(int id){
	if(id < n)
		return data[id + 1];
	return data[1];
}
void dp(int begin,int end){
	if(F[begin][end])
		return;
	if(begin == end){
		F[begin][end] = 0;
		return;
	}
	/*
	int MAX = data[begin + 1];
	for(int i = begin + 2;i <= end;i++)
		if(data[i] > MAX)
			MAX = data[i];
	*/
	for(int id = begin + 1;id <= end;id++){
		dp(begin,id - 1);
		dp(id,end);
		F[begin][end] = max(F[begin][end],F[begin][id - 1] + F[id][end] + data[begin] * data[id] * getEnd(end));
	}
}
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin >> n;
	int max = -1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&in[i]);
		if(in[i] > max)
			max = in[i];
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		if(in[i] == max){
			for(int j = i;j <= n;j++)
				data[j - i + 1] = in[j];
			for(int j = 1;j < i;j++)
				data[n - i + j + 1] = in[j];
			for(int i = 1;i <= n;i++)
			dp(1,n);
			if(F[1][n] > ans)
				ans = F[1][n];
		}
	}
	cout << ans;
	return 0;
}
