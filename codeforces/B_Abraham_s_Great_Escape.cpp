#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase)
{
    int n, k;
    cin >> n >> k;
    vector<string> grid(n, string(n, '.'));

    int i, j;
    for (i = 0; k > 0 && i < n; i++)
    {
        for (j = 0; k > 0 && j < n; j++)
        {
            grid[i][j] = 'U';
            k--;
        }
    }

    if (i == n && j == n - 1)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    grid[n - 1][n - 1] = 'L';
    for (i = 0; i < n - 1; i++)
    {
        if (grid[n - 1][i] != 'U')
            grid[n - 1][i] = 'R';
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
                grid[i][j] = 'D';
        }
    }

    for (auto &s : grid)
        cout << s << endl;
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