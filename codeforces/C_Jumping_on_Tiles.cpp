#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    string s; cin >> s;
    int n = sz(s);
    map<char, vector<int>> char_index;
    int m = 0;
    for(int i = 0; i < n; i++){
        char c = s[i];
        if((c >= s[0] and c <= s[n - 1]) or (c <= s[0] and c >= s[n - 1])){
            m++;
            char_index[c].push_back(i + 1);
        }
    }

    cout << abs(s[0] - s[n - 1]) << ' ' << m << endl;
    if(s[0] < s[n - 1]){
        for(auto &[c, vector] : char_index){
            for(auto &v : vector){
                cout << v << ' ';
            }
        }
    }else{
        for(auto it = char_index.rbegin(); it != char_index.rend(); it++){
            for(auto &v : it->second){
                cout << v << ' ';
            }
        }
    }
    cout << endl;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}