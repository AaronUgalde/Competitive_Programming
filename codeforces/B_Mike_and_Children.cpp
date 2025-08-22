#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    map<int, int> sum_times;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            sum_times[A[i]+A[j]]++;
        }
    }

    int max_frec = INT_MIN;
    for(auto &[sum, times] : sum_times){
        max_frec = max(max_frec, times);
        //cout << sum << ' ' << times << endl;
    }

    cout << max_frec << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}
