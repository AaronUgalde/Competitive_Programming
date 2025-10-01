#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<vector<int>> parent_child(n);
    set<int> parents;
    parents.insert(0);
    for(int i = 0; i < n - 1; i++){
        int x; cin >> x;
        parents.insert(x - 1);
        parent_child[x - 1].push_back(i + 1);        
    }

    for(auto &p : parents){
        int count = 0;
        for(auto &c : parent_child[p]){
            if(!parents.count(c)) count++;
        }
        if(count < 3){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}