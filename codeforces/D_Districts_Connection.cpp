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

    int point_1 = -1;
    int point_2 = -1;
    for(int i = 0; i<n; i++){
        if(point_1 == -1) point_1 = i;
        else if(A[i] != A[point_1]) point_2 = i;    
    }

    if(point_2 == -1){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << point_1+1 << ' ' << point_2+1 << endl;
    for(int i = 0; i<n; i++){
        if(i == point_1 || i == point_2) continue;
        if(A[i] != A[point_1]){
            cout << i+1 << ' ' << point_1+1 << endl;
        }else{
            cout << i+1 << ' ' << point_2+1 << endl;
        }
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