#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<string> A(n);
    for(auto &a : A) cin >> a;

    vector<int> frec(m);
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(A[i][j] == '1') frec[j]++;
        }
    }

    for(int i = 0; i < n; i++){
        bool can_ignore = true;
        for(int j = 0; j < m; j++){
            if(A[i][j] == '1' and frec[j] < 2){
                can_ignore = false;
                break;
            }
        }
        if(can_ignore){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}