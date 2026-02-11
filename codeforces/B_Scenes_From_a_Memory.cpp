#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int k; cin >> k;
    string n; cin >> n;
    vector<string> not_prime = {"1", "4", "6", "8", "9", "22", "32", "52", "72", "33", "25", "35", "55", "75", "27", "57", "77"};
    for(int i = 0; i < sz(not_prime); i++){
        int j = 0;
        for(int l = 0; l < k; l++){
            if(j < sz(not_prime[i]) and n[l] == not_prime[i][j]) j++;
        }
        if(j == sz(not_prime[i])){
            cout << sz(not_prime[i]) << endl;
            cout << not_prime[i] << endl;
            return;
        }
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