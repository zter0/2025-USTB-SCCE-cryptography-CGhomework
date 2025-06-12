#include <iostream>
using namespace std;

int eulerPhi(int n) {
    int result = n; // 初始化为n
    
    // 处理2的因子
    if (n % 2 == 0) {
        while (n % 2 == 0) {
            n /= 2;
        }
        result -= result / 2;
    }
    
    // 处理奇数因子
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    
    // 处理剩余的质因数
    if (n > 1) {
        result -= result / n;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    cout << eulerPhi(n) << endl;
    
    return 0;
}