#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

int mod(int x, int y){
    if(x >= 0){
        return x % y;
    }else{
        while(y + x < 0) x = y + x;
        return y + x;
    }
}

void solve(int testcase){
    char s, e; cin >> s >> e;
    map<int, char> mp1 = {
        {'v', 0},
        {'<', 1},
        {'^', 2},
        {'>', 3}
    };
    int n; cin >> n;
    int md_cw = mod(n, 4);
    if(md_cw == 0 or md_cw == 2){
        cout << "undefined" << endl;
        return;
    }


    if(mod(mp1[s] + n, 4) == mp1[e]){
        cout << "cw" << endl;
    }else if(mod(mp1[s] - n, 4) == mp1[e]){
        cout << "ccw" << endl;
    }else{
        cout << "undefined" << endl;
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