#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int q; cin >> q;
    vector<int> queries(q);
    for(auto &q : queries) cin >> q;

    int first = queries[0];
    bool down = false;
    vector<int> ans(q, 1);
    int last_1 = 0;
    for(int i = 1; i<q; i++){
        if(queries[i] >= queries[last_1] && !down){
            last_1 = i;
        }else if(queries[i] < queries[last_1] && queries[i] <= first && !down){
            down = true;
            last_1 = i;
        }else if(down){
            if(queries[i] >= queries[last_1] && queries[i] <= first){
                last_1 = i;
            }else{
                ans[i] = 0;
            }
        }else{
            ans[i] = 0;
        }
    }

    for(int i = 0; i<q; i++){
        cout << ans[i];
    }
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