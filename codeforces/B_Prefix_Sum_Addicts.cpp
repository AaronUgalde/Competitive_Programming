#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n, k; cin >> n >> k; 
    vector<ll> A(k);
    for(auto &a : A) cin >> a;

    vector<ll> diff(k - 1);
    for(int i = 0; i < k - 1; i++){
        diff[i] = A[i + 1] - A[i];
    }

    for(int i = 0; i < k - 2; i++){
        if(diff[i] > diff[i + 1]){
            cout << "No" << endl;
            return;
        }
    }

    if((k == 1) || diff[0] * (n - k + 1) >= A[0])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}