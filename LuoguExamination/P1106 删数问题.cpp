#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int k,in[260];
string ge;
int len;
int main(){
    cin >> ge >> k;
    len = ge.size();
    for(int i = 0;i < ge.size();i++){
        in[i] = ge[i] - '0';
    }
    for(int i = 1;i <= k;i++){
		for(int j = 0;j < len - 1;j++){
			if(in[j] > in[j + 1]){
				for(int k = j;k < len - 1;k++)
					in[k] = in[k + 1];
				break;
			}
		}
		len--;
	}
    bool flg = false;
    for(int i = 0;i <= len - 1;i++){
    	if(in[i] != 0)
    		flg = true;
    	if(flg)
    		cout << in[i];
    }
}
