#include<iostream>
#include<cstdio>
using namespace std;
long long data[100000];
long long c[100000],c_len = 1;
long long judge(int begin,int end){
	if(begin == end)
		return 0;
	int j = (begin + end) / 2;
	long long a = judge(begin,j);
	long long b = judge(j + 1,end);
	c_len = 1;
	int a_begin = begin,b_begin = j + 1;
	long long ans = 0;
	while(a_begin <= j && b_begin <= end){
		if(data[a_begin] <= data[b_begin])
			c[c_len++] = data[a_begin++];
		else{
			c[c_len++] = data[b_begin++];
			ans += j - a_begin + 1;
		}
	}
	while(a_begin <= j)
		c[c_len++] = data[a_begin++];
	while(b_begin <= end)
		c[c_len++] = data[b_begin++];
	c_len--;
	for(int i = 1;i <= c_len;i++)
		data[begin + i - 1] = c[i];
	return a + b + ans;
}
int main(){
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> data[i];
	cout << judge(1,n);
	return 0;
}
