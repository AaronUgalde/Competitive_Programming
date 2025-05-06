#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string s; cin >> s;
    string curr = "";
    vector<string> w;
    for(int i = 0; i<s.size(); i++){
        if(s[i] != ',' && s[i] != ';') curr += s[i];
        else{
            w.push_back(curr);
            curr = "";
        }
    }
    w.push_back(curr);

    vector<string> a, b;
    for(int i = 0; i<w.size(); i++){
        bool isNumber = (w[i][0] == '0' && w[i].size() == 1) || w[i][0] >= '1' && w[i][0] <= '9';
        for(int j = 1; j<w[i].size(); j++){
            if(!(w[i][j] >= '0' && w[i][j] <= '9')) isNumber = false;
        }
        if(isNumber) a.push_back(w[i]);
        else b.push_back(w[i]);
    }

    string A = "", B = "";
    for(int i = 0; i<a.size(); i++){
        A += a[i] + (i + 1 == a.size() ? "" : ",");
    }
 
    for(int i = 0; i<b.size(); i++){
        B += b[i] + (i + 1 == b.size() ? "" : ",");
    }

    char quote = 34;
    if(a.size()){
        cout << quote << A << quote << endl; 
    }else cout << "-" << endl;

    if(b.size()){
        cout << quote << B << quote << endl;
    }else cout << "-" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}