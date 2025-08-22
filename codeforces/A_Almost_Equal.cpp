#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    if(n % 2 == 0){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<int> ans(2*n);
    bool first = true;
    for(int i = 1, j = 0; i<=2*n;j++, i+=2){
        ans[j] = (first ? i : i + 1);
        ans[j+n] = (first ? i + 1 : i);
        first = !first;
    }

    for(auto &a : ans) cout << a << ' ';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}