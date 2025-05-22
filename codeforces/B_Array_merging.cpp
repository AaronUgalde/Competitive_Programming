#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<int> max_l_a(2*n+1, 0), max_l_b(2*n+1, 0);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    int n_i = 0;
    for(int i = 0; i<n-1; i++){
        if(a[i] == a[i+1]){
            n_i++;
            if(i+1 == n-1){
                n_i++;
                max_l_a[a[i]] = max(max_l_a[a[i]], n_i);
            }
        }else{
            n_i++;
            max_l_a[a[i]] = max(max_l_a[a[i]], n_i);
            n_i = 0;
            if(i+1 == n-1){
                n_i = 1;
                max_l_a[a[i+1]] = max(max_l_a[a[i+1]], n_i);
            }
        }
    }

    n_i = 0;
    for(int i = 0; i<n-1; i++){
        if(b[i] == b[i+1]){
            n_i++;
            if(i+1 == n-1){
                n_i++;
                max_l_b[b[i]] = max(max_l_b[b[i]], n_i);
            }
        }else{
            n_i++;
            max_l_b[b[i]] = max(max_l_b[b[i]], n_i);
            n_i = 0;
            if(i+1 == n-1){
                n_i = 1;
                max_l_b[b[i+1]] = max(max_l_b[b[i+1]], n_i);
            }
        }
    }

    if(n == 1){
        max_l_a[a[0]] = 1;
        max_l_b[b[0]] = 1;
    }

    int ans = 0;
    for(int i = 1; i<2*n+1; i++){
        ans = max(ans, max_l_a[i] + max_l_b[i]);
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