#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, x; cin >> n >> x;
    vector<int> doors(n);
    for(auto &d : doors) cin >> d;
    int i = 0;
    while(doors[i] == 0) i++;
    int j = n-1;
    while(doors[j] == 0) j--;
    cout << (j - i + 1 <= x ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}