#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

struct info_post{
    int pos;
    int mn;
    int mx;
};

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> A(n); iota(all(A), 1);
    vector<int> B(m);
    for(auto &b : B) cin >> b;

    map<int, info_post> post_info_post;
    for(int i = 0; i < n; i++){
        post_info_post[A[i]] = {i, i, i};
    }

    for(int i = 0; i < m; i++){
        int pos = post_info_post[B[i]].pos; 
        if(pos > 0){
            post_info_post[A[pos - 1]].mx = max(post_info_post[A[pos - 1]].mx, pos);
            post_info_post[A[pos - 1]].pos = pos;
            post_info_post[B[i]].mn = min(post_info_post[B[i]].mn, pos - 1);
            post_info_post[B[i]].pos = pos - 1; 
            swap(A[pos], A[pos - 1]); 
        }
    }

    for(auto &[post, info_post] : post_info_post){
        cout << info_post.mn  + 1 << ' ' << info_post.mx + 1 << endl;
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