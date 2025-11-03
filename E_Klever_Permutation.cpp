#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, k; cin >> n >> k;
    
    vector<int> p(n);
    int cnt_i = 1, cnt_j = n;
    for(int i = 0; i < k; i++){
        for(int j = i; j < n; j += k){
            if(i % 2 == 0){
                p[j] = cnt_i;
                cnt_i++;
            }else{
                p[j] = cnt_j;
                cnt_j--;
            }
        }
    }

    for(auto &x : p) cout << x << ' ';
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