#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    ll n, k; cin >> n >> k;
    vector<ll> mices(k);
    for(auto &mice : mices) cin >> mice;

    sort(all(mices), greater<ll>());

    int cat = 0;
    int saved = 0;
    for(int i = 0; i < k; i++){
        if(mices[i] > cat){
            cat += n - mices[i];
            saved++;
        }
    }

    cout << saved << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}