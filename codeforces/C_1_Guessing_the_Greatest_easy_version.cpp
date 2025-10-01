#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

int ask(int l, int r){
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int ans; cin >> ans;
    return ans - 1;
}

void solve(int testcase){
    int n; cin >> n;

    cout << "? " << 1 << ' ' << n << endl;
    int smax; cin >> smax; smax--;
    if(smax == n - 1 || (smax > 0  && smax == ask(0, smax))){
        int l = 0, r = smax;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(smax == ask(m, smax)){
                l = m;
            }else{
                r = m;
            }
        }
        cout << "! " <<  l + 1 << endl;
    }else{
        int l = smax, r = n - 1;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(smax == ask(smax, m)){
                r = m;
            }else{
                l = m;
            }
        }
        cout << "! " << r + 1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}