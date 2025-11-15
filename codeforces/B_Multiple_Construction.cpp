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
    vector<int> A(2 * n, 0);
    A[0] = n;
    A[n] = n;
    for(int i = 1; i <= n - 1; i++){
        A[i] = n - i;
        A[2 * n - i] = n - i;
    }

    for(auto &a : A) cout << a << ' ';
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