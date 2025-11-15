#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    vector<int> cnt(5);
    for(int i = 0; i < 3; i++){
        int x; cin >> x;
        if(x > 4) continue;
        cnt[x]++;
    }

    cout << (cnt[1] or (cnt[2] >= 2) or (cnt[4] == 2 and cnt[2] == 1) or (cnt[3] == 3) ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}