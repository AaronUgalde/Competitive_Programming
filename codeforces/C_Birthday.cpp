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

    sort(all(A));
    vector<int> order(n);
    for(int i = 0, j = n - 1, k = 0; k < n; k++){
        if(k % 2 == 0){
            order[i] = A[k];
            i++;
        }else{
            order[j] = A[k];
            j--;
        }
    }

    for(auto &o: order) cout << o << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}