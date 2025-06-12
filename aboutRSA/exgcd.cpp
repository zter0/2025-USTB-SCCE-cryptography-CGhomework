#include <iostream>
using namespace std;

// 扩展欧几里得算法，返回gcd(a, b)，并更新x和y使得a*x + b*y = gcd(a, b)
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

// 求a模b的逆元
int mod_inverse(int a, int b) {
    int x, y;
    int gcd = extended_gcd(a, b, x, y);
    if (gcd != 1) {
        // 逆元不存在
        return -1;
    } else {
        // 调整x为正数
        return (x % b + b) % b;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int inverse = mod_inverse(a, b);
    if (inverse == -1) {
        cout << "逆元不存在" << endl;
    } else {
        cout << inverse << endl;
    }
    return 0;
}