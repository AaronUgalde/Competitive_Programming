#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int diff = A[0] - A[1];
    for(int i = 1; i<(n-1); i++){
        if(A[i] - A[i+1] != diff){
            cout << "NO" << endl;
            return;
        }
    }

    sort(all(A));
    diff = abs(diff);

    int balance = A[0] - diff;
    if(balance % (n+1) == 0 && balance >= 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}