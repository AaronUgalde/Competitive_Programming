#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    string bin; cin >> bin;
    int carry = (bin[n-1] == '1');
    int operations = 0;
    bool one = carry;
    for(int i = n-2; i >= 0; i--){
        operations += carry;
        if(carry <= i+1) cout << operations << ' ';
        else cout << -1 << ' ';
        if(bin[i] == '1'){
            one = true;
            carry++;
        }
        //cout << "carry:" << carry << ' ';
    }
    cout << (one ? -1 : 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}