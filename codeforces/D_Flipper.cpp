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
    vector<int> P(n);
    for(auto &p : P) cin >> p;

    int r = max_element(P.begin() + 1, P.end()) - P.begin() - 1;
    if(r == n - 2) r = n - 1;


    vector<int> ans;
    for(int i = r + 1; i < n; i++){
        ans.push_back(P[i]);
    }

    ans.push_back(P[r]);
    int l = r;
    for(; l >= 0; l--){
        if(P[l - 1] > P[0]){
            ans.push_back(P[l - 1]);
        }else{
            break;
        }
    }

    for(int i = 0; i < l; i++){
        ans.push_back(P[i]);
    }

    for(auto &a : ans) cout << a << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}