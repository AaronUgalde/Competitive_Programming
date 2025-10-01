#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

const int MOD = 998244353;

void solve(int testcase)
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &a : A)
        cin >> a;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == (i == 0 ? 0 : A[i - 1]))
        {
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        }
        if (i >= 1 && A[i] == (i == 1 ? 0 : A[i - 2]) + 1)
        {
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
        }
    }

    cout << (dp[n] + dp[n - 1]) % MOD << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve(i);
    }
}