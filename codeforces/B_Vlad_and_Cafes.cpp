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

    map<int, int> cafe_first;
    for(int i = 0; i < n; i++){
        cafe_first[A[i]] = i;
    }

    int min_first = INT_MAX;
    int min_cafe = 0;
    for(auto &[cafe, first] : cafe_first){
        if(first < min_first){
            min_first = first;
            min_cafe = cafe;
        }
    }

    cout << min_cafe << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}