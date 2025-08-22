#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0; i<n; i++){
        cin >> A[i].first;
        A[i].second = i + 1;
    }

    sort(all(A));
    int i = 0, j = n - 1;
    int used = 0;
    vector<int> ans;
    while(i < j){
        while(used < A[i].first && j > i){
            ans.push_back(A[j].second);
            used++;
            j--;
        }
        used = 0;
        ans.push_back(A[i].second);
        i++;
    }

    for(auto &a : ans) cout << a << ' ';
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