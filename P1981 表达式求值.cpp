#include<cstdio> 
#include<stack>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;
stack<char>sf;
stack<long long> sc;
string in;
bool can(char a){
    if(sf.size()== 0)
        return false;
    if(a == '+')
        return true;
    if(a == '*')
        if(sf.top() == '*')
            return true;
    return false;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("expr.out","w",stdout);
    cin >> in;
    for(int i = 0;i < in.size();){
        long long c= 0;
        char f;
        while(in[i] >= '0' && in[i] <= '9'){
            c *= 10;
            c += in[i] - '0';
            i++;
        }
        c %= 10000;
        sc.push(c);
        f = in[i];
        while(can(f)){
            int fi = sc.top();
            sc.pop();
            long long se = sc.top();
            sc.pop();
            char a = sf.top();
            sf.pop();
            if(a == '+')
                sc.push((fi + se) % 10000);
            else 
                sc.push((fi * se) % 10000);
        }
        sf.push(f);
        i++;
    }
    sf.pop();
    while(sf.size() > 0){
        int fi = sc.top();
        sc.pop();
        int se = sc.top();
        sc.pop();
        char a = sf.top();
        sf.pop();
        if(a == '+')
            sc.push(fi + se);
        else 
            sc.push(fi * se);
    }
    int i = sc.top();
    cout << i % 10000;
}

