#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    string sin;
    while(getline(cin,sin)){
        int n;
        int f = 0,s = 0;
        bool flg = true;
        int a;
        stringstream st;
        st << sin;
        st >> n;
        for(int i = 1;i <= n;i++){
            st >> a;
            if(a > f && a > s){
                if(f > s)
                    f = a;
                else
                    s = a;
            }else if(a > f && a <= s)
                f = a;
            else if(a > s && a <= f)
                s = a;
            else{
                cout << "No!" << endl;
                flg = false;
                break;
            }
        }
        if(flg)
            cout << "Yes!" << endl;
    }
    return 0;
}
