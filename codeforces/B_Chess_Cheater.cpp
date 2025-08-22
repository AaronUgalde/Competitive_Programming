#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    bool last_w = false;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == 'W'){
            if(last_w) ans += 2;
            else ans++;
            last_w = true;
        }else{
            last_w = false;
        }
    }

    int pos_w = INT_MAX;
    vector<int> distances;
    int n_ls = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == 'W'){
            int dist = i - pos_w - 1;
            if(dist > 0) distances.push_back(dist);
            pos_w = i;
        }else{
            n_ls++;
        }
    }

    //cout << "ans: " << ans << endl;
    //cout << "distances: " << endl;
    //for(auto &d : distances) cout << d << endl;

    sort(all(distances));
    for(int i = 0; i<distances.size(); i++){
        if(distances[i] <= k){
            ans += distances[i]*2 + 1;
            k -= distances[i];
            n_ls -= distances[i];
        }else{
            break;
        }
    }

    ans += min(k, n_ls) * 2;
    if(n_ls == n && k) ans--;
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