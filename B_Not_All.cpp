#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    map<int, int> bucket;
    for(auto &a : A) cin >> a;
    for(auto &a : A) bucket[a]++;
    for(int i = n - 1, times = 0; i >= -1; times++, i--){
        for(int j = 1; j <= m; j++){
            if(bucket[j] == 0){
                cout << times << endl;
                return;
            }
        }
        bucket[A[i]]--;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}