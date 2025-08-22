#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int MAX_A = 1e9+1;

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    map<int, int> appeard;
    int id = 0;
    vector<pair<int, int>> ranges;
    int taken = 0;
    bool one = false;
    for(int i = 0; i<n; i++){
        if(!appeard.count(A[i]) || appeard[A[i]] != id){
            appeard[A[i]] = id;
            taken++;
        }else{
            ranges.emplace_back(i-taken+1, i+1);
            one = true;
            id++;
            taken = 0;
        }
    }

    if(!one){
        cout << -1 << endl;
        return;
    }

    ranges[ranges.size()-1].second = n;

    cout << ranges.size() << endl;
    for(auto &[l, r]: ranges){
        cout << l << ' ' << r << endl;
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