#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

bool can(string s, bool start){
    vector<int> asigned('z'-'a'+1, -1);
    for(int i = 0; i<s.size(); i++){
        if(asigned[s[i]-'a'] == -1){
            asigned[s[i]-'a'] = start;
        }else{
            if(asigned[s[i]-'a'] != start){
                return false;
            }
        }
        start = !start;            
    }
    return true;
}

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    cout << (can(s, 0) || can(s, 1) ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}