#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string s; cin >> s;
    int n_empty = 0;
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }else{
            st.pop();
            if(st.empty()) n_empty++;
        }
    }

    cout << (n_empty > 1 ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}