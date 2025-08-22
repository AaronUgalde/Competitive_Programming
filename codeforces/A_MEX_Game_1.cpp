#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    map<int, int> int_frec;
    for(auto &a : A) int_frec[a]++;

    bool one = false;
    int mex = *max_element(all(A)) + 1;
    int min_one = mex;
    for(int i = 0; i<n; i++){
        if(int_frec[i] == 0){
            mex = min(mex, i);
        }else if(int_frec[i] == 1){
            if(i < min_one){
                mex = min(mex, min_one);
                min_one = i;
            }else{
                mex = min(mex, i);
            }
        }
    }

    cout << mex << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}