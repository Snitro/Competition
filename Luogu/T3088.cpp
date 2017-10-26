#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a;
struct stor{
    int w;
    int c;
} ha[100000];
int main(){
    freopen("in.txt","r",stdin);
    cin >> a;
    for(;a > 0;a--){
    	int m,n,d;
		int s = 0,y = 0;
		int ans[10000];
    	cin >> m >> n >> d;
    	y = m;
	    m /= 1000;
	    for(int i = 1;i <= d;i++){
	        cin >> ha[i].w >> ha[i].c;
	        ha[i].w /= 1000;
	    }
		for(int p = 0;p < n;p++){
	    	memset(ans,0,sizeof(ans));
		    for(int i = 1;i <= d;i++){
		        for(int a = 1;a <= m;a++){
		            int b = ha[i].c + ans[a - ha[i].w];
		            if(a - ha[i].w < 0)
		                b = 0;
		            ans[a] = max(ans[a],b);
		            //cout << a << " : "<< ans[a] << "     ";
		        }
		       // cout << endl;
		    }
		    s += ans[m];
		    m = (y + s)/ 1000;
		}
		//cout << s << endl;
		cout << y + s << endl;
	}
}
