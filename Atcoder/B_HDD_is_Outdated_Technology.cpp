#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    map<ll, ll> frag_pos;
    for(int i = 0; i<n; i++){
        int frag; cin >> frag;
        frag_pos[frag] = i+1;
    }

    ll time = 0;
    for(int i = 1; i<n; i++){
        time += abs(frag_pos[i] - frag_pos[i+1]);
    }

    cout << time << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}