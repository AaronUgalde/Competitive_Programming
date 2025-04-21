#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool login = false;
    cin >> n;
    int ans = 0;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        if(s == "login"){
            login = true;
        }
        else if(s == "logout"){
            login = false;
        }
        else if(s == "private" && !login){
            ans++;
        }
    }
    cout << ans << endl;
}