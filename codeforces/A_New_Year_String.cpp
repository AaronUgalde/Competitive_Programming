#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    bool is_2026 = false;
    bool is_2025 = false;
    string s_2026 = "2026";
    string s_2025 = "2025";
    for(int i = 0; i < n - 3; i++){
        int j = i;
        for(; j < i + 4; j++){
            if(s[j] != s_2026[j - i]){
                break;
            }
        }
        if(j == i + 4) is_2026 = true;
        j = i;
        for(; j < i + 4; j++){
            if(s[j] != s_2025[j - i]){
                break;
            }
        }
        if(j == i + 4) is_2025 = true;
    }

    cout << (is_2026 or not is_2025 ? 0 : 1) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}