#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, k; cin >> n >> k;
    int minA = INT_MAX, maxA = INT_MIN;
    ll sum = 0;
    vector<int> A(n);
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        minA = min(minA, a);
        maxA = max(maxA, a);
        sum += a;
        A[i] = a;
    }

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(maxA == A[i]) cnt++;
    }

    if(maxA - minA > k){
        if(cnt > 1){
            cout << "Jerry\n"; 
            return;
        }else if(maxA - 1 - minA > k){
            cout << "Jerry\n";
            return;
        }
    }

    if(sum % 2 != 0){
        cout << "Tom\n";
    }else{
        cout << "Jerry\n";
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