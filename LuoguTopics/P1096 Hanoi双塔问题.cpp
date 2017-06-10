#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdio>
const int maxn = 1000;

/*
logn(a*b)=logn(a)+logn(b)
log10(n)+1即可求出n的位数
则2^p的位数=log10(2^p)+1=p*log10(2)+1
*/
using namespace std;
	struct BigInteger{
	int len, s[maxn];
	
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
		char s[maxn];
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
	
	BigInteger operator * (const BigInteger& b) {
		BigInteger c;
		c.len = len + b.len;
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
	
	BigInteger operator - (const BigInteger& b) {
		BigInteger c; c.len = 0;
		for(int i = 0, g = 0; i < len; i++) {
			int x = s[i] - g;
			if(i < b.len)
				x -= b.s[i];
			if(x >= 0)
				g = 0;
			else {
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	
	BigInteger operator % (const BigInteger& b){
		BigInteger c = *this;
		while(c > b){
			c = c - b;
		}
		return c;
	}
	
	bool operator < (const BigInteger& b) const{
		if(len != b.len) return len < b.len;
		for(int i = len-1; i >= 0; i--)
			if(s[i] != b.s[i])
				return s[i] < b.s[i];
		return false;
	}
	
	bool operator > (const BigInteger& b) const{
		return b < *this;
	}
	
	bool operator <= (const BigInteger& b) {
		return !(b > *this);
	}
	
	bool operator == (const BigInteger& b) {
		return !(b < *this) && !(*this < b);
	}
	
	BigInteger operator += (const BigInteger& b) {
		*this = *this + b;
		return *this;
	}
};

istream& operator >> (istream &in, BigInteger& x) {
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const BigInteger& x) {
	out << x.str();
	return out;
}

BigInteger ksm(BigInteger i,int n){
	if(n == 1){
		return i;
	}
	if(n == 0){
		BigInteger a = 1;
		return a;
	}
	int k = n / 2;
	BigInteger a = ksm(i,k);
	if(n % 2 == 0)
		return a * a;
	else
		return a * a * i;
}

int main(){
	int n;
	BigInteger a;
	BigInteger b = 2;
	a = 2;
	cin >> n;
	a = ksm(a,n);
	a = a - 1;
	a = b * a;
	cout << a;
}
