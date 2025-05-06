#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const ll INF = 1e13;

void solve(int testcase){
    int n; cin >> n;
    ll k; cin >> k;
    string s; cin >> s;

    vector<ll> a(n);
    int pos = -1;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(s[i] == '0'){
            a[i] = -INF;
            pos = i;
        }
    }

    ll curr = a[0];
    ll mx = a[0];
    for(int i = 1; i<n; i++){
        curr = max(curr + a[i], a[i]);
        mx = max(mx, curr);
    }

    if(mx > k || (pos == -1 && mx != k)){
        cout << "No\n";
        return;
    }

    if(pos != -1){
        ll b = 0;
        ll sum = 0;
        for(int i = pos - 1; i >= 0; i--){
            sum += a[i];
            b = max(b, sum);
        }
        
        ll c = 0;
        sum = 0;
        for(int i = pos + 1; i<n; i++){
            sum += a[i];
            c = max(c, sum);
        }

        a[pos] = k - (b + c);
    }

    cout << "Yes\n";
    for(int i = 0; i<n; i++){
        cout << a[i] << " \n"[i + 1 == n];
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}