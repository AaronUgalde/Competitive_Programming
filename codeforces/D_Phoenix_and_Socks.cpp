#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, l, r; cin >> n >> l >> r;
    map<int, int> bucket;
    for(int i = 0; i < l; i++){
        int c; cin >> c;
        bucket[c]++;
    }
    for(int i = 0; i < r; i++){
        int c; cin >> c;
        bucket[c]--;
    }

    int diff = l -r;
    int n_operations = 0;
    int left = 0;
    int right = 0;
    for(auto &[c, frec] : bucket){
        if(diff * frec > 0){
            int mod = diff > 0 ? min(diff, frec) : max(diff, frec);
            n_operations += abs(mod / 2);
            frec -= mod - mod % 2;
            diff -= mod - mod % 2;
        }
        if(frec > 0){
            left += frec;
        }else{
            right -= frec;
        }
    }


    int t = min(left, right);
    n_operations += t;
    left -= t;
    right -= t;
    n_operations += left + right;

    cout << n_operations << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}