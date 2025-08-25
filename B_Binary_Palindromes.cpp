#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    int good_one = 0;
    int good_zero = 0;
    int good = 0;
    int bad_one = 0;
    int bad_zero = 0;
    int bad = 0;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        int ones = 0, zeros = 0;
        for(int j = 0; j<sz(s); j++){
            if(s[j] == '1') ones++;
            else zeros++;
        }
        if((ones % 2 + zeros % 2) != 0 && sz(s) % 2 == 0){
            bad++;
        }else{
            good++;
        }

    }

    cout << n - (bad % 2 == 1 && good == 0) << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}