#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int pos = -1;
        for (int i = n - 1; i > 0; --i) {
            int a = s[i - 1] - '0';
            int b = s[i]     - '0';
            if (a + b >= 10) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            int sum = (s[pos - 1] - '0') + (s[pos] - '0');
            s[pos - 1] = char('0' + sum / 10);
            s[pos]     = char('0' + sum % 10);
            cout << s << "\n";
        } else {
            int sum = (s[0] - '0') + (s[1] - '0');
            cout << char('0' + sum) << s.substr(2) << "\n";
        }
    }

    return 0;
}
