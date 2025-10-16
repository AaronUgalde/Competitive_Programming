#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase)
{
    int n;
    cin >> n;
    int winers_group = n;
    int losers_group = 0;
    int matches = 0;

    while (winers_group > 1 || losers_group > 1)
    {
        int w_wg = winers_group / 2;
        int w_lg = losers_group / 2;
        matches += w_wg + w_lg;
        winers_group -= w_wg;
        losers_group += w_wg - w_lg;
    }

    cout << matches + 1 << endl;
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