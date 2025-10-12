#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (auto &a : A)
        cin >> a, a %= k;

    map<ll, ll> number_frec;
    for (auto &a : A)
        if (a != 0)
            number_frec[a]++;

    vector<pair<ll, ll>> v_number_frec;
    for (auto &[number, frec] : number_frec)
    {
        v_number_frec.emplace_back(k - number, frec);
    }

    if (sz(v_number_frec) == 0)
    {
        cout << 0 << endl;
        return;
    }

    sort(all(v_number_frec), [](const pair<ll, ll> a, const pair<ll, ll> b)
         {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first > b.first; });

    cout << v_number_frec[0].first + k * (v_number_frec[0].second - 1) + 1;

    cout << endl;
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