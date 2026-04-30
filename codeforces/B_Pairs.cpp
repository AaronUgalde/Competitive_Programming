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

    int x_1, x_2; cin >> x_1 >> x_2;
    vector<pair<int, int>> pairs(m - 1);
    for(int i = 1; i < m; i++){
        cin >> pairs[i - 1].first >> pairs[i - 1].second;
    }

    auto can_x = [&](int x){
        int n_x = 1;
        map<int, int> bucket;
        for(auto &[a, b] : pairs){
            if(a == x or b == x){
                n_x++;
                continue;
            }
            bucket[a]++;
            bucket[b]++;
        }

        int mx_y = 0;
        for(auto &[y, frec] : bucket){
            mx_y = max(mx_y, frec);
        }

        return(n_x + mx_y == m);
    }; 
    
    cout << (can_x(x_1) or can_x(x_2) ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}