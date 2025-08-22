#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, p, q; cin >> n >> p >> q;
    string s; cin >> s;

    int nq = -1;
    int np;
    for(int i = 0; i <= n/p; i++){
        np = i;
        int rem = n - p*np;
        if(rem % q == 0){
            nq = rem / q;
            break;
        }   
    }

    if(nq == -1){
        cout << -1 << endl;
        return;
    }

    cout << np + nq <<  endl;

    for(int i = 0; i<np; i++){
        for(int j = 0; j<p; j++){
            cout << s[p*i + j];
        }
        cout << endl;
    }

    for(int i = 0; i<nq; i++){
        for(int j = 0; j<q; j++){
            cout << s[np*p + q*i + j];
        }
        cout << endl;
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