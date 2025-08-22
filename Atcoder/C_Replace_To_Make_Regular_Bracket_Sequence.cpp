#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

bool isOpen(char c){
    return c == '(' || c == '[' || c == '{' || c == '<';
}

map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};

void solve(int testcase){
    string s; cin >> s;
    stack<char> st;
    int ans = 0;
    for(char &c : s){
        if(isOpen(c)){
            st.push(c);
        }else{
            if(!st.empty()){
                if(c != pairs[st.top()]){
                    ans++;
                }
                st.pop();
            }else{
                cout << "Impossible" << endl;
                return;
            }
        }
    }

    if(!st.empty()){
        cout << "Impossible" << endl;
        return;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}