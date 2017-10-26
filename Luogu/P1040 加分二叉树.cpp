#include<iostream>
#include<cstdio>
using namespace std;
int n;
int data[40];
long long F[40][40];
int F_id[40][40];
void dp(int left,int right){
	if(F[left][right])
		return;
	if(left == right){
		F[left][right] = data[left];
		return;
	}
	int ANS;
	for(int i = left + 1;i < right;i++){
		dp(left,i - 1);
		dp(i + 1,right);
		ANS = F[left][i - 1] * F[i + 1][right] + data[i];
		if(ANS > F[left][right]){
			F[left][right] = ANS;
			F_id[left][right] = i;
		}
	}
	dp(left + 1,right);
	dp(left,right - 1);
	ANS = F[left + 1][right] + data[left];
	if(ANS > F[left][right]){
		F[left][right] = ANS;
		F_id[left][right] = left;
	}
	ANS = F[left][right - 1] + data[right];
	if(ANS > F[left][right]){
		F[left][right] = ANS;
		F_id[left][right] = right;
	}
}
void print_anser(int left,int right){
	if(left == right){
		cout << left << " ";
		return;
	}
	cout << F_id[left][right] << " ";
	if(F_id[left][right] == left)
		print_anser(F_id[left][right] + 1,right);
	else if(F_id[left][right] == right)
		print_anser(left,F_id[left][right] - 1);
	else{
		print_anser(left,F_id[left][right] - 1);
		print_anser(F_id[left][right] + 1,right);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> n;
	int MIN = 200;
	for(int i = 1;i <= n;i++){
		scanf("%d",&data[i]);
		if(data[i] < MIN)
			MIN = data[i];
	}
	long long ans = -1;
	int ANS;
	for(int i = 1;i <= n;i++){
		if(i > 1 && i < n){
			dp(1,i - 1);
			dp(i + 1,n);
			ANS = F[1][i - 1] * F[i + 1][n] + data[i];
			if(ANS > ans){
				ans = ANS;
				F_id[1][n] = i;
			}
		}else if(i == 1){
			dp(i + 1,n);
			ANS = F[i + 1][n] + data[i];
			if(ANS > ans){
				ans = ANS;
				F_id[1][n] = i;
			}
		}else if(i == n){
			dp(1,i - 1);
			ANS = F[1][i - 1] + data[i];
			if(ANS > ans){
				ans = ANS;
				F_id[1][n] = i;
			}
		}
	}
	cout << ans << endl;
	print_anser(1,n);
	return 0;
}
