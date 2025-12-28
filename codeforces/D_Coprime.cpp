#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    map<int, int> number_last;
    set<int> unique_a;
    for(int i = 0; i < n; i++){
        number_last[A[i]] = i + 1;
        unique_a.insert(A[i]);
    }

    vector<int> v_a;
    for(auto &a : unique_a){
        v_a.push_back(a);
    }

    int ans = -1;
    for(int i = 0; i < sz(v_a); i++){
        for(int j = i; j < sz(v_a); j++){
            if(gcd(v_a[i], v_a[j]) == 1){
                ans = max(ans, number_last[v_a[i]] + number_last[v_a[j]]);
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}