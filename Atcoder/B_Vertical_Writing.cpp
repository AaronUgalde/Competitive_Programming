#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n; cin >> n;
    vector<string> S(n);
    for(auto &s : S) cin >> s;

    int i = 0;
    do{
        bool isLetter = false;
        string t = "";
        int lastletter = 0;
        for(int j = n - 1; j>=0; j--){
            if(i < S[j].size()){
                t += S[j][i];
                isLetter = true;
                lastletter = t.size();
            }else{
                t += '*';
            }
        }
        if(!isLetter){
            break;
        }
        for(int j = 0; j<lastletter; j++) cout << t[j];
        cout<< '\n';
        i++;
    }while(true);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}