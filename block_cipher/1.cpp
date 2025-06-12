#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int div_length;
string en_code;

int main() {
    cin >> en_code;
    cin >> div_length;
    int code_length = en_code.length();

    int i;
    for(i = 0; i + div_length < code_length; i += div_length) {
        cout << en_code.substr(i, div_length) << endl;
    }

    cout.setf(ios::left);
    cout.fill('#');
    cout.width(div_length);
    cout << en_code.substr(i) << endl;

    return 0;
}