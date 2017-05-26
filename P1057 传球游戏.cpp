#include<iostream>
using namespace std;
int e[35][35],n,m,i1,i2;
int main(){
	cin >> n >> m;
	for(int a = 1;a <= n;a++){
		e[a][1] = 0;
		if(a == 2||a == n)
			e[a][1] = 1;
	}
	for(int a = 2;a <= m;a++){	//交换次数 
		for(int b = 1;b <= n;b++){	// 人的序号 
			i1 = b - 1;
			i2 = b + 1;
			if(i1 == 0) 
				i1 = n;
			if(i2 == n+1)
				i2 = 1;
			e[b][a] = e[i1][a-1] + e[i2][a-1];
			if(a == m && b == 1){
				cout << e[1][a];
			}
		}
	}
	cout<<endl;
	for(int a = 1;a <= n;a++){
		for(int b = 1;b <= m;b++){
			cout<<e[a][b]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
