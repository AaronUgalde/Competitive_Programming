#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, x; cin >> n >> x;
    vector<int> A(n); 
    set<int> appears;
    for(auto &a : A){
        cin >> a;
        if(appears.count(a)){
            cout << 0 << endl;
            return;
        }
        appears.insert(a);
    } 

    set<int> appears_and;
    for(auto &a : A){
        appears.erase(a);
        int a_and = a & x;
        if(appears.count(a_and)){
            cout << 1 << endl;
            return;
        }
        appears.insert(a);
        appears_and.insert(a_and);
    }

    if(sz(appears_and) < n){
        cout << 2 << endl;
        return;
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}