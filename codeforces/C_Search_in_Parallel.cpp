#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n, s_1, s_2; cin >> n >> s_1 >> s_2;
    vector<pair<int, int>> R(n);
    for(int i = 0; i < n; i++){
        cin >> R[i].first;
        R[i].second = i;
    }

    int x = s_1, y = s_2;
    sort(all(R));
    reverse(all(R));
    vector<int> A, B;
    for(int i = 0; i < n; i++){
        if(x < y){
            A.push_back(R[i].second);
            x += s_1;
        }else{
            B.push_back(R[i].second);
            y += s_2;
        }
    }

    cout << sz(A) << ' ';
    for(auto &a : A) cout << a + 1 << ' ';
    cout << endl;
    cout << sz(B) << ' ';
    for(auto &b : B) cout << b + 1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}