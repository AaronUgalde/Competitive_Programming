#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }

    int restriction = -1;
    int maxA = INT_MIN, minA = INT_MAX;
    for(int i = 0; i < n; i++){
        if(b[i] != -1){
            if(restriction == -1){
                restriction = a[i] +  b[i];
            }else if(a[i] + b[i] != restriction){
                cout << "0\n";
                return;
            }
        }

        maxA = max(maxA, a[i]);
        minA = min(minA, a[i]);
    }
    
    if(maxA > restriction && restriction != -1){
        cout <<"0\n";
        return;
    }

    if(restriction - minA > k){
        cout << "0\n";
        return;
    }

    if(restriction != -1){
        cout << "1\n";
        return;
    }

    cout << k - (maxA - minA) + 1 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}