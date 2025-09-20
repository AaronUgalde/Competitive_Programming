#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())


void solve(int testcase){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    auto f = [&](int x){
        int operations = 0;
        bool start = false;
        for(int i = 0; i < n; i++){
            if(A[i] < x) continue;
            if(s[i] == 'B'){
                if(start) continue;
                operations++;
                start = true;
            }else{
                start = false;
            }
        }

        return operations <= k;
    };

    int l = -1, h = 1e9 + 1;
    while(h - l > 1){
        int m = l + (h - l) / 2;
        if(f(m)){
            h = m;
        }else{
            l = m;
        }
    }

    cout << max(l, 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}