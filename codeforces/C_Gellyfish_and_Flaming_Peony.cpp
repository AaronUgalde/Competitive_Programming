#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int MAX_N = 5001;

int all_gcds[MAX_N][MAX_N];

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    //Compute gcd(a_1, a_2, ..., a_n);
    int g = A[0];
    for(int i = 1; i<n; i++){
        g = all_gcds[g][A[i]];
    }

    //Count how many A[i] == g
    int cnt = 0;
    for(int i = 0; i<n; i++){
        cnt += (A[i] == g);
    }

    //if g already exists, we need n - cnt operations
    if(cnt > 0){
        cout << n - cnt << endl;
        return;
    }

    int mx = *max_element(all(A));
    vector<int> memo(mx+1, INT_MAX);

    //For making a, we need 0 operations
    for(auto &a : A){
        memo[a] = 0;
    }

    for(int i = mx; i >= 1; i--){
        if(memo[i] == INT_MAX) continue;
        for(int j = 0; j<n; j++){
            memo[all_gcds[i][A[j]]] = min(memo[all_gcds[i][A[j]]], memo[i] + 1);
        }
    }


    cout << memo[g] + n - 1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //Precompute all gcds
    for(int i = 0; i<MAX_N; i++){
        all_gcds[i][0] = i;
        all_gcds[0][i] = i;
        for(int j = 1; j<=i; j++){
            if(i == j) all_gcds[i][j] = i;
            else{
                all_gcds[i][j] = all_gcds[j][i%j];
            }
            all_gcds[j][i] = all_gcds[i][j];
        }
    }

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}