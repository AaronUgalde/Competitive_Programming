#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

bool colide(int i, int j, int k){
    return (i == j || i == k || j == k);
}

void print_pair(pair<int, int> p){
    cout << p.first << ' ' << p.second << endl; 
}

void solve(int testcase){
    int n; cin >> n;
    vector<pair<ll, ll>> A(n), B(n), C(n);
    for(int i = 0; i<n; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    for(int i = 0; i<n; i++){
        cin >> B[i].first;
        B[i].second = i;
    }
    for(int i = 0; i<n; i++){
        cin >> C[i].first;
        C[i].second = i;
    }

    sort(all(A));
    sort(all(B));
    sort(all(C));

    ll ans = 0;
    for(int i = n-1; i >= n-3; i--){
        for(int j = n-1; j >= n-3; j--){
            for(int k = n-1; k >= n-3; k--){
                if(!colide(A[i].second, B[j].second, C[k].second)) ans = max(ans, A[i].first + B[j].first + C[k].first);
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}