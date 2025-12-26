#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

bool cmp(const string &a, const string &b){
    return sz(a) < sz(b);
};

void solve(int testcase){
    int n; cin >> n;
    vector<string> S(n);
    for(auto &s : S) cin >> s;

    sort(all(S), cmp);

    for(int i = 0; i < n - 1; i++){
        if(sz(S[i]) == sz(S[i + 1])){
            if(S[i] != S[i + 1]){
                cout << "NO" << endl;
                return;
            }
        }else{
            bool is_sub = false;
            for(int j = 0; j < sz(S[i + 1]) - sz(S[i]) + 1; j++){
                if(S[i] == S[i + 1].substr(j, sz(S[i]))){
                    is_sub = true;
                }
            }
            if(!is_sub){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    for(auto &s : S) cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}