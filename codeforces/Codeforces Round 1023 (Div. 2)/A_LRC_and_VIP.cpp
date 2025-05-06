#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    int g = A[0];
    for(int i = 1; i < n; i++)
        g = gcd(g, A[i]);


    int idx = -1;
    for(int i = 0; i < n; i++){
        if(A[i] != g){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        cout << "No\n";
    }else {
        cout << "Yes\n";
        for(int i = 0; i < n; i++){
            cout << (i == idx ? 1 : 2) << ' ';
        }
        cout << "\n";
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