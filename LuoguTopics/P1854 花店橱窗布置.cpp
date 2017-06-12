#include<iostream>
#include<cstdio>
using namespace std;
int f,v;//  f 花束数   v花瓶数
int flower[105][105];
int F[105][105];
void print_anser(int line,int id){
	if(line == 0)
		return;
	if(F[line][id] == F[line - 1][id - 1] + flower[line][id]){
		print_anser(line - 1,id - 1);
		cout << id << " ";
	}else{
		int i = id - 1;
		while(F[line][i] == F[line][id])
			i--;
		i++;
		print_anser(line - 1,i - 1);
		cout << i << " ";
	}
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> f >> v;
	for(int i = 1;i <= f;i++)
		for(int j = 1;j <= v;j++)
			scanf("%d",&flower[i][j]);
	for(int i = 1;i <= f;i++){
		for(int j = i;j <= v;j++){
			F[i][j] = -999999999;
		}
	}
	F[1][1] = flower[1][1];
	for(int i = 2;i <= f;i++) // 第一束花特殊 
		F[1][i] = max(flower[1][i],F[1][i - 1]);
	for(int i = 2;i <= f;i++){
		for(int j = 1;j <= v - f + i;j++){
			for(int k = i;k <= j;k++)
				F[i][j] = max(F[i][j],F[i - 1][k - 1] + flower[i][k]);
		}
	}
	/*
	for(int i = 1;i <= f;i++){
		for(int j = 1;j <= v;j++){
			cout << F[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << F[f][v] << endl;
	print_anser(f,v);
	return 0;
}
