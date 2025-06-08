#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int l, r; cin >> l >> r;
    int L, R; cin >> L >> R;
    
    if(l >= R || L >= r){
        cout << 1  + (L == r) + (l == R) << endl;
        return;
    }

    if(l < L && r < R){
        cout << (r-L) + 2<< endl;
        return;
    }

    if(L < l && R < r){
        cout << (R-l) + 2<< endl;
        return;
    }

    if(l >= L && r <= R){
        cout << (r-l)  + (l != L) + (R != r) << endl;
        return;
    }

    if(L >= l && R <= r){
        cout << (R-L) + (l != L) + (R != r) << endl;
        return;
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