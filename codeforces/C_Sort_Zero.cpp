#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    map<int, int> int_time;
    int time = 0;
    int different = 0;
    int ans = 0;
    int greater = 0;
    for(int i = 0; i<n; i++){
        if(A[i] < greater || (int_time.count(A[i]) && int_time[A[i]] < time)){
            ans += different;
            time++;
            different = 0;
        }
        if(!int_time.count(A[i])){
            int_time[A[i]] = time;
            different++;
            greater = A[i];
        }
    }

    //for(auto &a : A) cout << a << ' ';
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}