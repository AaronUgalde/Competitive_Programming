#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; cin >> n;
    string x; cin >> x;
    
    bool defined_greatest = false;

    string a(n, ' '), b(n, ' ');
    for(int i = 0; i<n; i++){
        if(defined_greatest){
            a[i] = x[i];
            b[i] = '0';
        }else{
            if(x[i] == '2'){
                a[i] = '1';
                b[i] = '1';
            }else if(x[i] == '0'){
                a[i] = '0';
                b[i] = '0';
            }else{
                defined_greatest = true;
                b[i] = x[i];
                a[i] = '0';
            }
        }
    }

    cout << a << endl << b << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}