#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

int query(set<int> &s, int extra){
    cout << "? " << sz(s) + 1 << " ";
    for(auto &x: s) cout << x  + 1 << ' ';
    cout << extra + 1;
    cout << endl;
    int ans; cin >> ans;
    return ans;
}

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(2 * n);
    set<int> zero, not_zero;
    zero.insert(0);
    for(int i = 1; i < (2 * n); i++){
        int res_query = query(zero, i);
        if(res_query == 0){
            zero.insert(i);
        }else{
            A[i] = res_query;
            not_zero.insert(i);
        }
    }

    for(auto &x: zero){
        A[x] = query(not_zero, x);
    }

    cout << "! ";
    for(auto &a : A) cout << a << ' ';
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