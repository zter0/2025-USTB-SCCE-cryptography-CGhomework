#include<bits/stdc++.h>
#define re 
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
struct Big{
    int len,s[810];
    Big(){memset(s,0,sizeof(s)); len=1;}
    Big(int val) {*this=val;}
    Big(const char *val) {*this=val;}
    Big operator = (const int &val){
        re char s[810];
        sprintf(s,"%d",val);
        *this=s;return *this;
    }
    Big operator = (const char *val){
        len=strlen(val);
        while(len>1&&val[0]=='0') ++val,len--;
        for(re int i=0;i<len;++i) s[i]=val[len-i-1]-'0';
        return *this;
    }
    inline void deal(){
        while(len>1&&!s[len-1]) len--;
    }
    Big operator + (const Big &a) const {
        Big res; res.len=0;
        re int top=max(len,a.len),add=0;
        for(re int i=0;add||i<top;++i){
            re int now=add;
            if(i<len) now+=s[i];
            if(i<a.len) now+=a.s[i];
            res.s[res.len++]=now%10;
            add=now/10;
        }
        return res;
    }
    Big operator - (const Big &a) const {
        Big res; res.len=0;re int del=0;
        for(re int i=0;i<len;++i){
            re int now=s[i]-del;
            if(i<a.len) now-=a.s[i];
            if(now>=0) del=0;
            else del=1,now+=10;
            res.s[res.len++]=now;
        }
        res.deal(); return res;
    }
    Big operator * (const Big &a) const {
        Big res; res.len=len+a.len;
        for(re int i=0;i<len;++i)
            for(re int j=0;j<a.len;++j)
                res.s[i+j]+=s[i]*a.s[j];
        for(re int i=0;i<res.len;++i)
            res.s[i+1]+=res.s[i]/10,res.s[i]%=10;
        res.deal(); return res;
    }
    Big operator / (const Big &a) const {
        Big res,cur=0;res.len=len;
        for(re int i=len-1;~i;--i){
            cur=cur*10,cur.s[0]=s[i];
            while(cur>=a)
                cur-=a,res.s[i]++;
        }
        res.deal(); return res;
    }
    Big operator % (const Big &a) const {
        Big res=*this/a;
        return *this-res*a;
    }
    Big operator += (const Big &a) {*this=*this+a; return *this;}
    Big operator -= (const Big &a) {*this=*this-a; return *this;}
    Big operator *= (const Big &a) {*this=*this*a; return *this;}
    Big operator /= (const Big &a) {*this=*this/a; return *this;}
    Big operator %= (const Big &a) {*this=*this%a; return *this;}
    bool operator < (const Big &a) const {
        if(len!=a.len) return len<a.len;
        for(re int i=len-1;~i;i--)
        if(s[i]!=a.s[i]) return s[i]<a.s[i];
        return false;
    }
    bool operator >  (const Big &a) const {return a<*this;}
    bool operator <= (const Big &a) const {return !(*this>a);}
    bool operator >= (const Big &a) const {return !(*this<a);}
    bool operator == (const Big &a) const {return !(*this>a||*this<a);}
    bool operator != (const Big &a) const {return *this>a||*this<a;}
};
inline Big Sqrt(const Big &x){
    re int a[510],top=0;
    for(re int i=0;i<x.len;i+=2){
        if(i==x.len-1) a[top++]=x.s[i];
        else a[top++]=x.s[i]+x.s[i+1]*10;
    }
    Big res=(int)sqrt((double)a[top-1]);
    re int dat=(int)sqrt((double)a[top-1]);
    Big pre=a[top-1]-dat*dat,val;
    for(re int i=top-2;~i;--i){
        pre=pre*100+a[i],val=res*20;
        for(re int j=9;~j;--j){
            Big now=(dat+j)*j;
            if(now>pre) continue;
            res=res*10+j;pre-=now; break;
        }
    }
    return res;
}
inline void print(const Big &a){
    for(re int i=a.len-1;~i;--i)
        printf("%d",a.s[i]); 
    puts("");
}

Big PowMod(Big a, Big b, Big p) {
	Big ret = 1;
	while(b != 0) {
		if(b % 2 != 0)
            ret = ret * a % p;
		a = a * a % p;
		b /= 2;
	}
	return ret;
}


int main() {
    char A[810], B[810], P[810];
    scanf("%s%s%s", A, B, P);
    Big a(A), b(B), p(P);
    Big ans = PowMod(a, b, p);
    print(ans);
    return 0;
}