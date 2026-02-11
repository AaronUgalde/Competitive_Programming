#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    for(int i = 0; (1 << i) <= max(a, b); i++){
        if(((a >> i) & 1) != ((b >> i) & 1)){
            if((1 << i) <= a){
                ans.push_back(1 << i);
            }else{
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << sz(ans) << endl;
    for(auto &a : ans){
        cout << a << ' ';
    }

    if(sz(ans) != 0) cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}