#include<iostream>
#include<cstdio>
using namespace std;
int n,p;
long long number[1000005];
long long t[1000005];
long long f[1000005];
int main(){
    freopen("in.txt","r",stdin);
    //freopen("number.out","w",stdout);
    scanf("%d%d",&n,&p);
    for(int i = 1;i <= n;i++){
    	cin >> number[i];
    }
    t[0] = 0;
    for(int i = 1;i <= n;i++){
        if(t[i - 1] >= 0)
            t[i] = t[i - 1] + number[i];
        else
			t[i] = number[i];
    }
    for(int i = 2;i <= n;i++)
        if(t[i - 1] > t[i])
            t[i] = t[i - 1];
            /*
    for(int i = 1;i <= n;i++)
    	cout << t[i] << " ";
    cout << endl;
    */
    f[1] = t[1];
    f[2] = t[1] + f[1];
    long long ans = max(f[1],f[2]);
    bool flg = f[1] < f[2];
    for(int i = 3;i <= n;i++){
    	if(!flg){
	        if(t[i - 1] > 0)
	            f[i] = f[i - 1] + t[i - 1];
	        else
	            f[i] = f[i - 1];
	        if(f[i] > f[1])
	        	flg = true;
	        if(ans < f[i])
	        	ans = f[i];
    	}else{
    		if(t[i - 1] > 0)
	            f[i] = f[i - 1] % p + t[i - 1] % p;
	        else
	            f[i] = f[i - 1] % p;
	        ans = f[i] % p;
    	}
    }
    cout << ans % p;
    return 0;
}
