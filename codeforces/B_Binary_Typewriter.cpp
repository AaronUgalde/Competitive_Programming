#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    int button = 0;
    int zero_one = (s[0] == '1');
    int one_zero = 0;
    int operations = 0;
    for(int i = 0; i<n-1; i++){
        if(s[i] == '0' && s[i+1] == '1') zero_one++;
        else if(s[i] == '1' && s[i+1] == '0') one_zero++;
        if(s[i] - '0' == button){
            operations++;
        }else{
            operations += 2;
            button = (button + 1) % 2;
        }
    }
    operations = (s[n-1] - '0' == button ? operations + 1 : operations + 2);

    if(zero_one >= 2 || one_zero >= 2){
        operations -= 2;
    }else if((zero_one && s[n-1] == '0') || one_zero && s[n-1] == '1'){
        operations--;
    }

    cout << operations << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}