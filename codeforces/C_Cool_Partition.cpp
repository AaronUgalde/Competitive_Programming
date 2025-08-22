#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    vector<set<int>> part(n);
    part[0] = {A[0]};
    int current_part = 1;
    int ans = 1;
    for(int i = 1; i<n; i++){
        part[current_part].insert(A[i]);
        if(part[current_part-1].count(A[i])){
            part[current_part-1].erase(A[i]);
        }
        if(part[current_part-1].size() == 0){
            ans++;
            current_part++;
        }
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