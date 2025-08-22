#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void printVec(vector<int> &vec){
    for(auto &v : vec) cout << v << ' ';
    cout << endl;
}


void solve(int testcase){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> s_p(n, -1);
    for(int i = 0; i<n; i++){
        int j = 0;
        for(; j<n; j++){
            if(t[i] == s[j] && s_p[j] == -1){
                s_p[j] = i;
                break;
            }
        }
        if(j == n){
            cout << -1 << endl;
            return;
        }
    }

    int ans = 0;
    vector<int> swaps;
    for(int i = 0; i<n; i++){
        if(s_p[i] == i) continue;
        for(int j = i; j<n; j++){
            if (s_p[j] == i){
                ans += j - i;
                for(; j > i; j--){
                    s_p[j] = s_p[j-1];
                    swaps.push_back(j);
                }
                s_p[i] = i;
                break;
            }
        }
    }

    cout << ans << endl;
    for(auto &sw : swaps) cout << sw << ' ';
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