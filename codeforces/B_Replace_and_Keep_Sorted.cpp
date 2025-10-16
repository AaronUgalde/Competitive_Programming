#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct info_prefix
{
    int down;
    int up;
    int total;
};

void solve(int testcase)
{
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> A(n);
    for (auto &a : A)
        cin >> a;

    vector<info_prefix> prefix(n + 1, {0, 0, 0});
    for (int i = 0; i < n; i++)
    {
        int down = (i == 0 ? A[i] - 1 : A[i] - A[i - 1] - 1);
        int up = (i == n - 1 ? k - A[i] : A[i + 1] - A[i] - 1);
        prefix[i + 1].total += prefix[i].total + up + down;
        prefix[i + 1].down = down;
        prefix[i + 1].up = up;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r].total - prefix[l - 1].total - prefix[l].down - prefix[r].up + (A[l - 1] - 1) + (k - A[r - 1]) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve(i);
    }
}