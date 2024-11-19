#include <bits/stdc++.h>

using namespace std;

void solve() {
    string str;

    cin >> str;

    unsigned int length = str.length() - 1;

    for (int i = 0; i <= length; ++i) {
        int ok = 1;
        for (int k = i, r = length; k <= length; ++k, --r) {
            if (str[k] != str[r]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << str;
            for (int j = i - 1; j >= 0; --j) {
                cout << str[j];
            }
            break;
        }
    }
}

int main() {
    while (1)
        solve();

    return 0;
}
