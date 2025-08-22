#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    vector<int> tasks(n);
    ll total = 0;
    for(auto &task : tasks) cin >> task, total += task;
    sort(all(tasks), greater<int>());

    ll div = total / n;
    ll rem = total % n;
    ll ans = 0;

    for(auto &task : tasks){
        ans += abs(task - (div + (rem > 0 ? 1 : 0)));
        rem--;
    }

    cout << ans / 2 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}