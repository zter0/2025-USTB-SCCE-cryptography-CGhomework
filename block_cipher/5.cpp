#include <iostream>
using namespace std;

#define POLY 0x11B // GF(2^8) 的本原多项式 x^8 + x^4 + x^3 + x + 1

unsigned char gf_add(unsigned char a, unsigned char b) {
    return a ^ b;
}

unsigned char gf_mul(unsigned char x, unsigned char y) {
    unsigned char result = 0;
    while (y) {
        if (y & 1) 
            result ^= x; // 如果最低位是 1，就加到结果
        y >>= 1;
        x = (x << 1) ^ (x & 0x80 ? 0x1B : 0); // 处理溢出，GF(2^8) 乘法
    }
    return result;
}

unsigned char gf_inv(unsigned char a) {
    if (a == 0) 
        return 0;
    unsigned char result = 1, power = 254; // 费马小定理，a^(2^8 - 2)
    while (power--) {
        result = gf_mul(result, a);
    }
    return result;
}


// GF(2^8) 除法：a / b = a * b^{-1}
unsigned char gf_div(unsigned char a, unsigned char b) {
    if (b == 0) 
        return 0;
    return gf_mul(a, gf_inv(b)); // a / b = a * b^(-1)
}


int main() {
    string a_str, b_str;
    cin >> a_str >> b_str;
    unsigned char a = stoi(a_str, nullptr, 16);
    unsigned char b = stoi(b_str, nullptr, 16);
    
    unsigned char inv_a = gf_inv(a);
    unsigned char sum = gf_add(a, b);
    unsigned char quotient = gf_div(a, b);
    
    cout << "0x" << hex << (int)inv_a << " 0x" << (int)sum << " 0x" << (int)quotient << endl;
    return 0;
}
