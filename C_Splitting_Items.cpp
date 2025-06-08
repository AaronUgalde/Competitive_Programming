#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A), greater<int>());

    for(int i = 1; i < n; i+=2){
        int t = A[i];
        A[i] = min(A[i-1], A[i]+k);
        k -= abs(t - A[i]);
    }

    int x = 0, y = 0;
    for(int i = 0; i<n; i++){
        if(i%2 == 0) x += A[i];
        else y += A[i];
    }

    cout << x - y << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}