#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    string s;
    cin >> s;

    map<char, int> encode = {
        {'R', 0},
        {'P', 1},
        {'S', 2}
    };

    map<int, char> decode = {
        {0, 'R'},
        {1, 'P'},
        {2, 'S'}
    };

    vector<int> cnt = {a, b, c};
    string ans(n, '?');
    int wins = 0;

    for (int i = 0; i < n; i++) {
        int bob = encode[s[i]];
        int me = (bob + 1) % 3;   // mano que le gana a bob

        if (cnt[me] > 0) {
            ans[i] = decode[me];
            cnt[me]--;
            wins++;
        }
    }

    if (wins < (n + 1) / 2) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == '?') {
            for (int x = 0; x < 3; x++) {
                if (cnt[x] > 0) {
                    ans[i] = decode[x];
                    cnt[x]--;
                    break;
                }
            }
        }
    }

    cout << "YES\n" << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}