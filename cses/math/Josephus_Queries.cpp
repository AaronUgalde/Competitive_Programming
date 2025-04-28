#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod(ll a, ll b) {
    ll r = a % b;
    if (r < 0) r += b;
    return r;
}

ll f(ll n, ll k) {
    if (n == 1) {
        return 0;
    }
    if (k <= n/2) {
        ll a = (2 * k) - 1;
        return a;
    }
    if (mod(n, 2) != 0) {
        ll sub = f(n - n/2, k - n/2) - 1;
        ll bprima = mod(sub, n - n/2);
        ll b = 2 * bprima;
        return b;
    } else {
        ll c = 2 * f(n - n/2, k - n/2);
        return c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << f(n, k) + 1 << "\n";
    }
    return 0;
}
