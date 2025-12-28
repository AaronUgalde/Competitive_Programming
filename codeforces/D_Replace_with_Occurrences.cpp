#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct element{
    int cnt;
    int assigned;
};

void solve(int testcase){
    int n; cin >> n;
    vector<int> B(n);
    map<int, int> number_frec;
    for(auto &b : B) cin >> b, number_frec[b]++;

    map<int, element> mp;
    for(auto &[number, frec] : number_frec){
        if(frec % number != 0){
            cout << -1 << endl;
            return;
        }
        
        mp[number] = {0, -1};
    }

    int j = 1;
    for(int i = 0; i < n; i++){
        if(mp[B[i]].cnt == 0){
            mp[B[i]].assigned = j;
            j++;
        }
        cout << mp[B[i]].assigned << ' ';
        mp[B[i]].cnt = (mp[B[i]].cnt + 1) % B[i];
    }
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