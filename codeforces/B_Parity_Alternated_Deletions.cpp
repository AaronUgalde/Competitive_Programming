#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A));
    vector<int> evens, odds;
    for(int i = 0; i<n; i++){
       if(A[i] % 2 == 0) evens.push_back(A[i]);
       else odds.push_back(A[i]); 
    }

    if(evens.size() - odds.size() == 0){
        cout << 0 << endl;
        return;
    }
    cout << (evens.size() > odds.size() ? accumulate(evens.begin(), evens.begin() + (evens.size() - odds.size() - 1), 0) : accumulate(odds.begin(), odds.begin() + (odds.size() - evens.size() - 1), 0)) << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}

// 8 7 5 2 1
// 7 5 1
// 8 2


