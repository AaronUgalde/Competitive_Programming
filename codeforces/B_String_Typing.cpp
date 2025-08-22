#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s; 

    int best_copy = 0;
    for(int i = 1; i < n - 1; i++){
        int j = 0, k = i;
        while(j < i && k < n && s[j] == s[k]) j++, k++;       
        if(j == i) best_copy = max(best_copy, j);
    }

    cout << n - best_copy + (best_copy > 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}