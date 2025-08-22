#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int k; cin >> k;
    
    if(k < 25){
        cout << -1 << endl;
        return;
    }
    string vowels = "aeiou";
    for(int i = 5; i<=k; i++){
        if(k % i == 0 && k / i >= 5){
            string row = vowels + vowels.substr(0, i - 5);
            for(int j = 0; j < (k/i); j++){
                cout << row;
                rotate(row.begin(), row.begin()+1, row.end());
            }
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}