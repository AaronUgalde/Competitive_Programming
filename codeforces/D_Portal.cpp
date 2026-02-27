#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, x, y; cin >> n >> x >> y;
    vector<int> P1, P2;
    for(int i = 0; i < x; i++){
        int p; cin >> p;
        P1.push_back(p);
    }
    for(int i = x; i < y; i++){
        int p; cin >> p;
        P2.push_back(p);
    }
    for(int i = y; i < n; i++){
        int p; cin >> p;
        P1.push_back(p);
    }

    rotate(P2.begin(), min_element(all(P2)), P2.end());

    int i = 0;
    for(; i < sz(P1); i++){
        if(P1[i] < P2[0]){
            cout << P1[i] << ' ';
        }else{
            break;
        }
    }


    for(auto &p : P2) cout << p << ' ';


    for(; i < sz(P1); i++) cout << P1[i] << ' ';
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