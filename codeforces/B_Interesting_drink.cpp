#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct query{
    int id;
    int m;
    int ans;
};

void solve(int testcase){
    int n; cin >> n;
    vector<int> X(n);
    for(auto &x : X) cin >> x;

    sort(all(X));

    int q; cin >> q;
    vector<query> qs(q);
    for(int i = 0; i < q; i++){
        qs[i].id = i;
        cin >> qs[i].m;
    }

    auto comp_m = [&](const query &a, const query &b){
        return a.m < b.m;
    };
    auto comp_id = [&](const query &a, const query &b){
        return a.id < b.id;
    };

    sort(all(qs), comp_m);

    int i_x = 0;
    for(int i = 0; i < q; i++){
        while(i_x < n and qs[i].m >= X[i_x]){
            i_x++;
        }
        qs[i].ans = i_x;
    }

    sort(all(qs), comp_id);
    for(auto &que: qs){
        cout << que.ans << endl;
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