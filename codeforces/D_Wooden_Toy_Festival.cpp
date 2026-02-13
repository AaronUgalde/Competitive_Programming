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

    sort(all(A));

    auto check = [&](int m){
        int used = 1;
        int x = A[0];
        for(int i = 0; i < n; i++){
            if(A[i] > x + 2 * m){
                used++;
                x = A[i];
            }
        }
        return (used <= 3 ? true : false);
    };

    int l = -1, r = 1e9 + 1;
    while(r - l > 1){
        int m = midpoint(l, r);
        if(check(m)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}