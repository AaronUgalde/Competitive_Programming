#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int MAXA = 1e6;
vector<int> a(MAXA, -1);

void solve(int testcase){
    int n; cin >> n;
    int mn = INT_MAX;
    bool exist = false;
    for(int i = 0; i<n; i++){
        int x; cin >> x; x--;
        if(a[x] != -1){
            mn = min(mn, i - a[x] + 1);
            exist = true;
        }else{
            a[x] = i;
        }
    }

    cout << (!exist ? -1 : mn) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}