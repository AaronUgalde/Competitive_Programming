#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    map<int, int, greater<int>> bucket;
    vector<int> scores; 
    for(int i = 0; i<n; i++){
        int p; cin >> p;
        scores.push_back(p);
        bucket[p]++;
    }

    int r = 1;
    vector<int> rank(101);
    for(auto &[score, n_score] : bucket){
        rank[score] = r;
        r += n_score;
    }

    for(int i = 0; i<scores.size(); i++){
        cout << rank[scores[i]] << endl;
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