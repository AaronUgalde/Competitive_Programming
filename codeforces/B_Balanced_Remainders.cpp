#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<int> c(3);
    for(auto &a : A){
        c[a % 3]++;
    }

    int balance = accumulate(all(c), 0) / 3;
    int ans = 0;
    
    for(int i = 0; c[0] != c[1] || c[0] != c[2] || c[1] != c[2]; i = (i + 1) % 3){
        if(c[i] < balance){
            c[((i - 1) % 3 < 0 ? 2 : (i - 1) % 3)] -= (balance - c[i]);
            ans += (balance - c[i]);
            c[i] = balance;
        }else{
            c[(i + 1) % 3] += c[i] - balance;
            ans += c[i] - balance;
            c[i] = balance;
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