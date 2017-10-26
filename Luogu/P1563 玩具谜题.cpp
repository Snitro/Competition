#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int id = 0;
struct elem_type {
    int f; // 0 ³¯ÄÚ || 1 ³¯Íâ 
    char name[11];
}data[100000];
int main() {
//	freopen("in.in","r",stdin);
    cin >> n >> m;
    for(int a = 0;a<n;a++){
        cin>>data[a].f>>data[a].name;
    }
    int in1,in2,current = 0;
    for(int a = 0;a<m;a++){
        cin>>in1>>in2;
        if(in1 == data[id].f)
        	id =  (id - in2 + n) % n;
        else
        	id = (id + in2) % n;
    }
    cout<<data[id].name;
    return 0;
}
