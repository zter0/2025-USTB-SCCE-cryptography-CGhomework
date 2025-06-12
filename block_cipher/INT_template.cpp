#include <bits/stdc++.h>

using namespace std;

class INT {
private:
    int len, s[810];
	inline void DeleteZero() {
		while(len > 1 && !s[len - 1]) 
			len --;
	} // to delete pervious 0

public:
    INT() { 
        memset(s, 0, sizeof s);
        len = 1;
    } // initialize as 0
	INT(int val) {
        char vals[810];
		sprintf(vals, "%d", val);
		new(this) INT(vals);
    } // initialize by int
    INT(const char* val) {
		len = strlen(val);
		while(len > 1 && val[0] == '0') {
			val ++;
			len --;
		} // delete pervious zero
		for(int i = 0; i < len; i ++)
			s[i] = val[len - 1 - i] - '0';
    } // initialize by char* or string
	INT(const INT& val) {
		len = val.len;
		for(int i = 0; i < len; i ++) {
			s[i] = val.s[i];
		}
	} // initialize by another INT

	INT operator = (const INT& val) {
		len = val.len;
		for(int i = 0; i < len; i ++) {
			s[i] = val.s[i];
		}
		return *this;
	}
    
	// basic operators +-*/%
	const friend INT operator + (const INT& l, const INT& r);
	const friend INT operator - (const INT& l, const INT& r);
	const friend INT operator * (const INT& l, const INT& r);
	const friend INT operator / (const INT& l, const INT& r);
	const friend INT operator % (const INT& l, const INT& r);

	// self operators
	INT operator += (const INT r) {
		*this = *this + r;
		return *this;
	}
	INT operator -= (const INT r) {
		*this = *this - r;
		return *this;
	}
	INT operator *= (const INT r) {
		*this = *this * r;
		return *this;
	}
	INT operator /= (const INT r) {
		*this = *this / r;
		return *this;
	}
	INT operator %= (const INT r) {
		*this = *this % r;
		return *this;
	}
	INT operator ++ () {
		*this = *this + 1;
		return *this;
	}
	INT operator -- () {
		*this = *this - 1;
		return *this;
	}
    
	// logical operators
	friend bool operator < (const INT&l, const INT& r);
	friend bool operator > (const INT&l, const INT& r);
	friend bool operator <= (const INT&l, const INT& r);
	friend bool operator >= (const INT&l, const INT& r);
	friend bool operator == (const INT&l, const INT& r);
	friend bool operator != (const INT&l, const INT& r);

	// write INT number and put ch after writing
    inline void print(const char& ch = '\n') const {
		for(int i = len - 1; i >= 0; i --) 
			printf("%d", s[i]);
		putchar(ch);
	}
};

const INT operator + (const INT& l, const INT& r) {
	INT res;
	res.len = 0;
	int top = max(l.len, r.len);
	int add = 0;
	for(int i = 0; add || i < top; i ++) {
		int now = add;
		if(i < l.len) 
			now += l.s[i];
		if(i < r.len)
			now += r.s[i];
		res.s[res.len ++] = now % 10;
		add = now / 10;
	}
	return res;
}
const INT operator - (const INT& l, const INT& r) {
	INT res;
	res.len = 0;
	int del = 0;
	for(int i = 0; i < l.len; i ++) {
		int now = l.s[i] - del;
		if(i < r.len)
			now -= r.s[i];
		if(now >= 0)
			del = 0;
		else
			del = 1, now += 10;
		res.s[res.len ++] = now;
	}
	res.DeleteZero();
	return res;
} // no minors
const INT operator * (const INT& l, const INT& r){
	INT res;
	res.len = l.len + r.len;
	for(int i = 0; i < l.len; i ++)
		for(int j = 0 ; j < r.len; j ++) 
			res.s[i + j] += l.s[i] * r.s[j];
	for(int i = 0; i < res.len; i ++) { 
		res.s[i + 1] += res.s[i] / 10;
		res.s[i] %= 10;
	}
	res.DeleteZero();
	return res;
}
const INT operator / (const INT& l, const INT& r) {
	INT res, cur = 0;
	res.len = l.len;
	for(int i = l.len - 1; i >= 0; i --) {
		cur = cur * 10;
		cur.s[0] = l.s[i];
		while(cur >= r) {
			cur -= r;
			res.s[i] ++;
		}
	}
	res.DeleteZero();
	return res;
}
const INT operator % (const INT& l, const INT& r) {
	INT res = l / r;
	return l - res * r;
}

// logical operators
bool operator < (const INT&l, const INT& r) {
	if(l.len != r.len)
		return l.len < r.len;
	for(int i = l.len - 1; i >= 0; i --) {
		if(l.s[i] != r.s[i])
			return l.s[i] < r.s[i];
	}
	return false;
}
bool operator > (const INT& l, const INT& r) {
	return r < l;
}
bool operator <= (const INT& l, const INT& r) {
	return !(l > r);
}
bool operator >= (const INT& l, const INT& r) {
	return !(l < r);
}
bool operator == (const INT& l, const INT& r) {
	return !(l < r || l > r);
}
bool operator != (const INT& l, const INT& r) {
	return !(l == r);
}

int main() {
	return 0;
}