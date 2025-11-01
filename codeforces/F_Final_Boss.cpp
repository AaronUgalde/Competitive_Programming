#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int h, n; cin >> h >> n;
    vector<int> A(n);
    vector<int> C(n);
    for(int &a : A) cin >> a;
    for(int &c : C) cin >> c;

    set<pair<ll, ll>> S;
    for(int i = 0; i < n; i++){
        S.insert({1, i});
    }

    ll last_turn = 1;
    while(h > 0){
        auto [turn, index] = *S.begin();
        S.erase(S.begin());
        last_turn = turn;
        h -= A[index];
        S.insert({turn + C[index], index});
    }

    cout << last_turn << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}