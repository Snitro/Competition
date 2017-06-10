#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c[7];
int j[7] = {0,1,2,3,5,10,20};
bool f2[1005][10];
bool f[1005];
int main(){
    freopen("in.txt","r",stdin);
    f[0] = true;
    for(int i = 1;i <= 6;i++)
        cin >> c[i];
    int m = 1 * c[1] + 2 * c[2] + 3 * c[3] + 5 * c[4] + 10 * c[5] + 20 * c[6];
    for(int i = 1;i <= 6;i++){
        for(int g = 1;g <= c[i];g++){
            for(int z = m;z >= 1;z--){
            	if(z - g * j[i] < 0)
            		continue;
                if(f[z - g * j[i]])
                    f2[z][g] = true;
            }
        }
        for(int g = 1;g <= c[i];g++){
            for(int z = m;z >= 1;z--){
            	f[z] = f[z] || f2[z][g];
            }
        }
        memset(f2,0,sizeof(f2));
        /*
        for(int z = 1;z <= m;z++)    
            cout << f[z] << " ";
        cout << endl;
        */
    }
    int ans = 0;
    for(int z = 1;z <= m;z++)    
        if(f[z])
            ans++;
    cout << "Total=" << ans;
}
