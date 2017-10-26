#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;

struct BigInteger{
    int len, s[100];

    BigInteger() {
        memset(s, 0, sizeof(s));
        len = 1;
    }

    BigInteger(int num) {
        *this = num;
    }

    BigInteger(const char* num) {
        *this = num;
    }

    BigInteger operator = (int num) {
        char s[100];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    BigInteger operator = (const char* num) {
        len = strlen(num);
        for(int i = 0; i < len; i++)
            s[i] = num[len - i - 1] - '0';
        return *this;
    }

    string str() const {
        string res = "";
        for(int i = 0; i < len; i++)
            res = (char)(s[i] + '0') + res;
        if(res == "")
            res = "0";
        return res;
    }

    BigInteger operator + (const BigInteger& b) const{
        BigInteger c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
            int x = g;
            if(i < len)
            x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    void clean() {
        while(len > 1 && !s[len-1])
            len--;
    }

    BigInteger operator * (const BigInteger& b) const{
        BigInteger c; c.len = len + b.len;
        for(int i = 0; i < len; i++)
          for(int j = 0; j < b.len; j++)
            c.s[i+j] += s[i] * b.s[j];
        for(int i = 0; i < c.len-1; i++){
          c.s[i+1] += c.s[i] / 10;
          c.s[i] %= 10;
        }
        c.clean();
        return c;
    }

    bool operator < (const BigInteger& b) const{
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }
    
    void out() {
    	for (int i = len - 1; i >= 0; i--)
    		printf("%d", s[i]);
	}
    
} f[85][85], pow[100], datas[85];

BigInteger solve() {
    BigInteger ans;
    
    memset(f, 0, sizeof(f));
    
    for (int l = 1; l <= m; l++)
        for (int r = m; r >= l; r--) {
            if (l > 1)
                f[l][r] = max(f[l][r], f[l - 1][r] + pow[ l - 1 + m - r] * datas[l - 1]);
            if (r < m)
                f[l][r] = max(f[l][r], f[l][r + 1] + pow[l - 1 + m - r] * datas[r + 1]);
        }
    
    for (int i = 1; i <= m; i++)
        ans = max(ans, f[i][i] + pow[m] * datas[i]);
    
    return ans;
}

void init() {
    pow[0]= 1;
    
    for (int i = 1; i < 100; i++)
        pow[i] = pow[i - 1] * 2;
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%d%d", &n, &m);
    
    init();
    
    BigInteger ans;
    
    int in;
    
    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= m; i++) {
        	scanf("%d", &in);
        	datas[i] = in;
		}
        ans = ans + solve();
    }
    
    ans.out();
    
    return 0;
}
