#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct data{
	int lie[50005],lie2[50005],len,len2;
	static bool cmp1(int a,int b){
		return a < b;
	}
	static bool cmp2(int a,int b){
		return a > b;
	}
	int da(){
		while(len2 != 1){
			sort(lie,lie + len2,cmp2);
			lie[len2 - 2] = lie[len2 - 1] * lie[len2 - 2] + 1;
			len2--;
		}
		return lie[0];
	}
	int xi(){
		while(len != 1){
			sort(lie2,lie2 + len,cmp1);
			lie2[len - 2] = lie2[len - 1] * lie2[len - 2] + 1;
			len--;
		}
		return lie2[0];
	}
};
int main(){
	freopen("in.txt","r",stdin);
	int i;
	while(cin >> i){
		if(i == 0)
			return 0;
		data in;
		in.len = i;
		in.len2 = in.len;
		for(int i = 0;i < in.len;i++){
			cin >> in.lie[i];
			in.lie2[i] = in.lie[i];
		}
		cout << in.da() - in.xi() << endl;
		//cout << in.da() << " " << in.xi();
	}
}
