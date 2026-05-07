#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> answer;
    int l = 0, r = n - 1;
    while (true){
        while(l < n and s[l] != '1'){
            l++;
        }
        while(r >= 0 and s[r] != '0'){
            r--;
        }
        if(l < r and s[l] == '1' and s[r] == '0'){
            answer.push_back(l);
            answer.push_back(r);
            l++;
            r--;
        }else{
            break;
        }
    }

    sort(all(answer));
    if(sz(answer) == 0){
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << sz(answer) << ' ';
    for(auto &a : answer){
        cout << a + 1 << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}