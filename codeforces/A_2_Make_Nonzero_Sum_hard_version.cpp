#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void remove_zeros(vector<pair<int, int>> &ans, int &i, vector<int> &A){
    int start = i;
    while(i < A.size() && A[i] == 0) i++;
    if(i != start) ans.emplace_back(start + 1, i);
}

void solve(int testcase){
    int n; cin >> n;
    int n_ones = 0;
    vector<int> A(n);
    for(auto &a : A){
        cin >> a;
        if(a == 1 || a == -1) n_ones++;
    }

    if(n_ones % 2 != 0){
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> ans;
    int i = 0;
    while(i < n){
        remove_zeros(ans, i, A);
        if(i >= n) break;
        int j = i+1;
        while(A[j] == 0) j++;
        int sign = ((j-i-1) % 2 == 0 ? 1 : -1);
        if(A[i] != A[j]*sign){
            ans.emplace_back(i+1, i+1);
            if(sign == -1){
                if(j - 1 > i + 1) ans.emplace_back(i+2, j-1);
                ans.emplace_back(j, j+1);
            }else{
                if(j > i + 1) ans.emplace_back(i+2, j);
                ans.emplace_back(j+1, j+1);
            }
        }else{
            ans.emplace_back(i+1, j+1);
        }
        i = j+1;
    }

    cout << sz(ans) << endl;
    for(auto &[l, r] : ans) cout << l << ' ' << r << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}