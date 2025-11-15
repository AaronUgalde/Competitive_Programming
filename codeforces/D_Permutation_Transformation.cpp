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

    vector<int> d(n);
    auto make_tree = [&](auto &&self, int l, int r, int last_d) -> void {
        if(r < l or l > r) return;
        int i_mx = l;
        int mx = A[l];
        for(int i = l; i <= r; i++){
            if(A[i] > mx){
                i_mx = i;
                mx = A[i];
            }
        }
        d[i_mx] = last_d + 1;
        self(self, l, i_mx - 1, last_d + 1);
        self(self, i_mx + 1, r, last_d + 1);
    };

    make_tree(make_tree, 0, n - 1, -1);

    for(auto &depth : d) cout << depth << ' ';
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