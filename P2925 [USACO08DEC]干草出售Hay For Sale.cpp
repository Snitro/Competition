#include<iostream>
using namespace std;
int c,h;//c容量 h种情况 
int f[50005];
int v[50005];
int main(){
    cin >> c >> h;
    for(int i = 1;i <= h;i++)
        cin >> v[i];
    for(int i = 1;i <= h;i++){
        for(int a = c;a >= v[i];a--){
        	if(f[a] == a)
        		continue;  //此时f[a]已经取到最大值 就不用再对f[a]进行更新 
            if(f[a - v[i]] + v[i] > f[a])
                f[a] = f[a - v[i]] + v[i];
        }
        if(f[c] == c){//判断是否已经能够装满c体积的干草
            cout << c;//能够装满
            return 0;//退出
        }
    }
    cout << f[c];
    return 0;
}
