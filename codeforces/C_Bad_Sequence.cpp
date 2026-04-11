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
    
    int balance = 0;
    bool close = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '(')
            balance++;
        else{
            if(balance - 1 < 0){
                if(!close) close = true;
                else{
                    cout << "No" << endl;
                    return;
                }
            }else{
                balance--;
            }
        }
    }

    if(close){
        if(balance == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if(balance){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}