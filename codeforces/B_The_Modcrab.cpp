#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int h1, a1, c1; cin >> h1 >> a1 >> c1;
    int h2, a2; cin >> h2 >> a2;
    vector<string> ans;
    while(h2 > 0){
        if(h1 > a2 || a1 >= h2){
            ans.push_back("STRIKE");
            h2 -= a1;
        }else{
            ans.push_back("HEAL");
            h1 += c1;
        }
        h1 -= a2;
    }

    cout << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}