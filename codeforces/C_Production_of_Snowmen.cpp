#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cout << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n), B(n), C(n);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;
    for(auto &c : C) cin >> c;


    auto check = [&](vector<int> &a, vector<int> &b){
        for(int i = 0; i < n; i++){
            if(a[i] >= b[i]){
                return false;
            }
        }
        return true;
    };

    long long x = 0;
    vector<int> copy_B = B;
    for(int i = 0; i < n; i++){
        if(check(A, copy_B)){
            x++;
        }
        rotate(copy_B.begin(), copy_B.begin() + 1, copy_B.end());
    }
    x *= n;

    long long y = 0;
    set<int> good_cb;
    for(int i = 0; i < n; i++){
        if(check(B, C)){
            y++;
        }
        rotate(B.begin(), B.begin() + 1, B.end());
    }

    long long ans = x * y;

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