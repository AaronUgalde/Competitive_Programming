#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<vector<ll>> prefix(n + 1, vector<ll>(32, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 32; j++){
            prefix[i + 1][j] = prefix[i][j] + ((A[i] >> j) & 1);
        }
    }

    auto f = [&](int l, int r){
        ll sum = 0;
        for(int i = 0; i < 32; i++){
            sum += ((prefix[r + 1][i] - prefix[l][i]) == (r - l + 1) ? 1 << i : 0);
        }
        return sum;
    };

    auto search_r = [&](int l, int k){
        int low = l - 1, high = n;
        while(high - low > 1){
            int mid = midpoint(low, high);   
            if(f(l, mid) < k){
                high = mid;
            }else{
                low = mid;
            }
        }
        return high - 1;
    };

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int l, k; cin >> l >> k;
        l--;
        cout << (A[l] >= k ? search_r(l, k) + 1 : -1) << ' ';
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